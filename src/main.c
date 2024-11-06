#include <stdio.h>
#include <string.h>
#include "../include/utils.h"
int main(int argc, char *argv[]) {
    char *language = NULL;
    char *filename = NULL;
    if (argc < 2) {
        printf("Usage: %s code_file\n", argv[0]);
        return 1;
    }
    language = get_lang(argv[1]);
    filename = argv[1];
    return 0;
}
