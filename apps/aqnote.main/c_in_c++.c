#undef __cplusplus

#ifdef __cplusplus
extern "C" {
#endif

int printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

int main(int argc, char **argv) {
    printf("aqnote.com\n");

    return 0;
}