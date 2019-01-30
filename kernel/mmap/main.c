
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/mman.h>
#include <sys/stat.h>

void mmapcopy(int fd, int size)
{
    char *bufp;
    bufp = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (bufp == (void *)-1)
        fprintf(stderr, "mmap: %s\n", strerror(errno));

    memcpy(bufp, "aqnote", 6);

    write(1, bufp, size);
    munmap(bufp, size);
    return;
}
int main(int argc, char **argv)
{
    struct stat stat;
    if (argc != 2)
    {
        printf("error.\n");
        exit(0);
    }
    
    int fd = open(argv[1], O_RDWR, 0); // O_RDWR 才能被读写
    if (fd < 0)
        fprintf(stderr, "open: %s\n", strerror(errno));
    
    fstat(fd, &stat);
    mmapcopy(fd, stat.st_size);
    close(fd);

    exit(0);
}
