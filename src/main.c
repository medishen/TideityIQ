#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/utils.h"
#include "../include/file_reader.h"
#include "../include/analyze.h"
#include "../include/calc_complexity.h"
int main(int argc, char *argv[]) {
    char *language = NULL;
     if (argc == 1 && (strcmp(argv[0], "tdq") == 0)) {
        system("bash ./bin/tdq");
        return 0;
    }
    // Ensure that the user provides a file argument
    if (argc < 2) {
        printf("Usage: tdq <code_file>\n");
        return 1;
    }
    language = get_lang(argv[1]);
    if (strcmp(language, "unknown") == 0) {
        printf("Unsupported file type.\n");
        return 1;
    }
    AnalysisData data = {0};
    read_file(argv[1], language, &data);
    calculate_complexity(&data);
    return 0;
}
