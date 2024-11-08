#include <stdio.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/parser.h"
int main(int argc, char *argv[]) {
    char *language = NULL;
    if (argc < 2) {
        printf("Usage: %s code_file\n", argv[0]);
        return 1;
    }
    language = get_lang(argv[1]);
    char *file_content = read_file(argv[1]);
    printf("File Content:\n%s\n", file_content);
    return 0;
}
