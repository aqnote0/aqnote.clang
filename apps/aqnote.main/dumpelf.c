//
// N A M E : d u m p e l f . C
//
// D E S C : Dump ELF32 header information
//
// A U T H : Wataru Nishida, M.D., Ph.D.
//           wnishida@skyfree.org
//           http://www.skyfree.org/
//
// M A K E : gcc -o dumpelf dumpelf.C
//
// V E R S : 0.10
//
// D A T E : Sep 3rd, 2000
//

#include <stdlib.h>
#include <stdio.h>
#include <linux/elf.h>

// typedef char int8_t;
typedef unsigned char  uint8_t;
typedef short          int16_t;
typedef unsigned short uint16_t;
typedef int            int32_t;
typedef unsigned       uint32_t;

// static void        show_elf(union elf_header);
static const char *read_table(const char **, int);
static void        error_quit(const char *);
static void        load_elf(void);
static void        show_elf(void);
static void        load_sheaders(void);
static void        show_sheader(int);
static void        show_sheaders(void);
static void        load_nametbl(void);
static void        load_pheaders(void);
static void        show_pheader(int);
static void        show_pheaders(void);

const int MaxSections = 40; // Maximum number of section headers
const int MaxPrograms = 20; // Maximum number of program headers
FILE *    Object;           // Object file pointer
char *    Names;            // Section name table copy buffer

//
// ELF header definition
//

union elf_header {
    struct eh {
        struct {                                    // ID tag
            uint8_t magic0, magic1, magic2, magic3; //   ELF magic ID
            uint8_t fclass,                         //   File class
                encoding,                           //   Little or big endian?
                version,                            //   File version
                padpos,                             //   Start pos of padding
                pads[8];                            //   Padding space
        } id;
        uint16_t type;      // Object file type
        uint16_t cpu;       // CPU architecture
        uint32_t version;   // Object file version
        uint32_t entry;     // Virtual address for the entry
        uint32_t ph_offset; // Offset address of program header
        uint32_t sh_offset; // Offset address of section header
        uint32_t flags;     // Processor-specific flags
        uint16_t eh_size;   // This header size
        uint16_t ph_size;   // Size of a program header
        uint16_t ph_num;    // Number of program header(s)
        uint16_t sh_size;   // Size of a section header
        uint16_t sh_num;    // Number of section header(s)
        uint16_t sh_name;   // Index of a sect header for name tbl.
    } header;
    char image[sizeof(struct eh)]; // Alias of elf_header.header{}.
} Elf;

// ELF file class

static const char *elf_class[] = {"Invalid", "32-bit objects", "64-bit objects",
                                  ""};

// ELF data encoding

static const char *elf_encoding[] = {"Invalid", "Little endian", "Big endian",
                                     ""};

// ELF file type

static const char *elf_type[] = {"None",   "Relocatable", "Executable",
                                 "Shared", "Core",        ""};

// ELF target CPU

static const char *elf_cpu[] = {"None",  "WE32100", "SPARC", "80386", "68000",
                                "88000", "80486",   "80860", "R3000", ""};

// ELF file version

static const char *elf_version[] = {"Invalid", "Current", ""};

//
// Program header definition
//

union program_header {
    struct ph {
        uint32_t type;     // Segment types
        uint32_t foffset;  // Offset in the file
        uint32_t vaddress; // Virtual address in memory
        uint32_t paddress; // Physical address in memory
        uint32_t fsize;    // Size in file image
        uint32_t msize;    // Size in memory
        uint32_t flags;    // Flags
        uint32_t align;    // Address alignment
    } header;
    char image[sizeof(struct ph)]; // Alias of program_header.header{}.
} Program[MaxPrograms];

// Segment type

static const char *segment_type_abbr[] = {"NULL", "LOAD", "DYNM", "INTP",
                                          "NOTE", "SLIB", "PHDR", ""};

//
// Section header definition
//

union section_header {
    struct sh {
        uint32_t name;     // Section name index
        uint32_t type;     // Section types
        uint32_t flags;    // Flags: WRITE, ALLOC, EXECINSTR
        uint32_t maddress; // Address in the memory image
        uint32_t foffset;  // Offset in the file
        uint32_t size;     // Section's size in bytes
        uint32_t link;     // Section header tbl idx link
        uint32_t info;     // Extra information
        uint32_t align;    // Address alignment
        uint32_t tblsize;  // Size of fixed-size table entry
    } header;
    char image[sizeof(struct sh)]; // Alias of section_header.header{}.
} Section[MaxSections];

// Section type

static const char *section_type_abbr[] = {
    "NULL", "PROG", "SYMT", "STRT", "RELA", "HASH", "DYNM",
    "NOTE", "NOSP", "RELO", "SLIB", "DSYM", ""};

//
// m a i n
//
//   --- welcome to dumpelf!
//
//						Sep.3, 2000

main(int argc, char **argv) {
    int i, ch;

    Object = fopen(argv[1], "r");
    if (!Object)
        exit(1);

    load_elf();
    load_pheaders();
    load_sheaders();
    load_nametbl();

    show_elf();
    show_pheaders();
    show_sheaders();

    fclose(Object);
}

//
//  e r r o r _ q u i t
//
//   --- report error and abondon this process
//
//						Sep.6, 2000

static void error_quit(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    if (Object)
        fclose(Object);
    if (Names)
        free(Names);
    exit(-1);
}

//
// r e a d _ t a b l e
//
//   --- read an indexed string from a table
//
//						Sep.3, 2000

static const char *read_table(const char **table, int idx) {
    int size;

    if (idx < 0)
        return ("");
    for (size = 0;; size++) // Check table size.
        if (*table[size] == 0)
            break;
    if (idx > (size - 1)) // Out of index.
        return ("");
    return (table[idx]); // Return string of specified idx.
}

//
// l o a d _ e l f
//
//   --- load ELF header into memory
//
//						Sep.6, 2000

static void load_elf(void) {
    int ret;

    ret = (int)fread(Elf.image, (size_t)sizeof(Elf), 1, Object);
    if (ret != 1)
        error_quit("File read error!");
}

//
// s h o w _ e l f
//
//   --- output ELF header information
//
//						Sep.3, 2000

static void show_elf(void) {
    printf("[ ELF header ]\n");
    printf("         Header ID: 0x%02X %c %c %c\n", Elf.header.id.magic0,
           Elf.header.id.magic1, Elf.header.id.magic2, Elf.header.id.magic3);
    printf("       ELF version: %s\n",
           read_table(elf_version, Elf.header.id.version));
    printf("   ELF header size: %d\n", Elf.header.eh_size);
    printf("        File class: %s\n",
           read_table(elf_class, Elf.header.id.fclass));
    printf("     Data encoding: %s\n",
           read_table(elf_encoding, Elf.header.id.encoding));

    printf("      Pad position: %d\n", Elf.header.id.padpos);
    printf("\n");
    printf("         File type: %s\n", read_table(elf_type, Elf.header.type));
    printf("        Target CPU: %s\n", read_table(elf_cpu, Elf.header.cpu));
    printf("      File version: %s\n",
           read_table(elf_version, Elf.header.version));
    printf("     Entry address: %X\n", Elf.header.entry);
    printf("   Processor flags: %X\n", Elf.header.flags);
    printf("  Name table index: %d\n", Elf.header.sh_name);
    printf("\n");
    printf("* Program header table\n");
    printf("            Offset: %d\n", Elf.header.ph_offset);
    printf("       Header size: %d\n", Elf.header.ph_size);
    printf(" Number of headers: %d\n", Elf.header.ph_num);
    printf(" Total header size: %d\n", Elf.header.ph_size * Elf.header.ph_num);
    printf("\n");
    printf("* Section header table\n");
    printf("            Offset: %d\n", Elf.header.sh_offset);
    printf("       Header size: %d\n", Elf.header.sh_size);
    printf(" Number of headers: %d\n", Elf.header.sh_num);
    printf(" Total header size: %d\n", Elf.header.sh_size * Elf.header.sh_num);
    printf("\n");
}

//
// l o a d _ p h e a d e r s
//
//   --- load program headers into memory
//
//						Sep.8, 2000

static void load_pheaders(void) {
    int ret;

    if (Elf.header.ph_num > MaxPrograms)
        error_quit("Too many program headers!");
    ret = fseek(Object, Elf.header.ph_offset, SEEK_SET);
    if (ret)
        error_quit("File seek error!");
    for (int i = 0; i < Elf.header.ph_num; i++) {
        ret =
            (int)fread(Program[i].image, (size_t)Elf.header.ph_size, 1, Object);
        if (ret != 1)
            error_quit("File read error!");
    }
}

//
// s h o w _ p h e a d e r s
//
//   --- output a program header table
//
//						Sep.8, 2000

static void show_pheaders(void) {
    printf("[ Program headers ]\n");
    printf(
        "Idx Type  Offset     VMA      PMA      FSIZ     MSIZ  Flag   Algn\n");
    printf(
        "-----------------------------------------------------------------\n");
    for (int i = 0; i < Elf.header.ph_num; i++)
        show_pheader(i);
    printf("\n");
}

//
// s h o w _ p h e a d e r
//
//   --- output contents of a program header
//
//						Sep.8, 2000

static void show_pheader(int idx) {
    union program_header *ph       = &Program[idx];
    char                  flags[4] = "   ";

    printf("%2d) ", idx);
    printf("%4s ", read_table(segment_type_abbr, ph->header.type));
    printf("%8d ", ph->header.foffset);
    printf("%8X ", ph->header.vaddress);
    printf("%8X ", ph->header.paddress);
    printf("%8d ", ph->header.fsize);
    printf("%8d  ", ph->header.msize);
    if (ph->header.flags & PF_R)
        flags[0] = 'R';
    if (ph->header.flags & PF_W)
        flags[1] = 'W';
    if (ph->header.flags & PF_X)
        flags[2] = 'X';
    printf("%s ", flags);
    printf("%6d\n", ph->header.align);
}

//
// l o a d _ s h e a d e r s
//
//   --- load section headers into memory
//
//						Sep.6, 2000

static void load_sheaders(void) {
    int ret;

    if (Elf.header.sh_num > MaxSections)
        error_quit("Too many section headers!");
    ret = fseek(Object, Elf.header.sh_offset, SEEK_SET);
    if (ret)
        error_quit("File seek error!");
    for (int i = 0; i < Elf.header.sh_num; i++) {
        ret =
            (int)fread(Section[i].image, (size_t)Elf.header.sh_size, 1, Object);
        if (ret != 1)
            error_quit("File read error!");
    }
}

//
// s h o w _ s h e a d e r s
//
//   --- output a section header table
//
//						Sep.8, 2000

static void show_sheaders(void) {
    printf("[ Section headers ]\n");
    printf("Idx       Name       Type Flag   VMA     Offset   Size   Lnk Inf "
           "Algn Tbl\n");
    printf("-------------------------------------------------------------------"
           "------\n");
    for (int i = 0; i < Elf.header.sh_num; i++)
        show_sheader(i);
    printf("\n");
}

//
// s h o w _ s h e a d e r
//
//   --- output contents of a section header
//
//						Sep.8, 2000

static void show_sheader(int idx) {
    union section_header *sh       = &Section[idx];
    char                  flags[4] = "   ";

    printf("%2d) ", idx);
    printf("%-16s ", &Names[sh->header.name]);
    printf("%4s ", read_table(section_type_abbr, sh->header.type));
    if (sh->header.flags & SHF_WRITE)
        flags[2] = 'W';
    if (sh->header.flags & SHF_ALLOC)
        flags[1] = 'A';
    if (sh->header.flags & SHF_EXECINSTR)
        flags[0] = 'X';
    printf("%s ", flags);
    printf("%8X ", sh->header.maddress);
    printf("%8d ", sh->header.foffset);
    printf("%8d ", sh->header.size);
    printf("%3d ", sh->header.link);
    printf("%3d ", sh->header.info);
    printf("%4d ", sh->header.align);
    printf("%3d\n", sh->header.tblsize);
}

//
// l o a d _ n a m e t b l
//
//   --- load a section name table
//
//						Sep.8, 2000

static void load_nametbl(void) {
    uint32_t offset, size;
    int      ret;

    if (!Elf.header.sh_name)
        return;
    offset = Section[Elf.header.sh_name].header.foffset;
    size   = Section[Elf.header.sh_name].header.size;
    Names  = (char *)malloc((size_t)size);
    if (!Names)
        error_quit("Memory allocation error!");
    ret = fseek(Object, (long)offset, SEEK_SET);
    if (ret)
        error_quit("File seek error!");
    ret = (int)fread(Names, (size_t)size, 1, Object);
    if (ret != 1)
        error_quit("File read error!");
}
