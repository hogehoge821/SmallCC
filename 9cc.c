#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "incorrect number of arguments");
        return 1;
    }
    char *p = argv[1];

    puts(".globl main");
    puts("main:");
    printf("  mov w0, %ld\n", strtol(p, &p, 10));

    while (*p) {
        if (*p == '+') {
            p++;
            printf("  add w0, w0, %ld\n", strtol(p, &p, 10));
            continue;
        }
        if (*p == '-') {
            p++;
            printf("  sub w0, w0, %ld\n", strtol(p, &p, 10));
            continue;
        }
        fprintf(stderr, "unexpected char: '%c'\n", *p);
        return 1;
    }
    puts("  ret");
    return 0;
}



