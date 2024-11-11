#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file_reader.h"
#include "../include/analyze.h"
void read_file(const char *filename, const char *language, AnalysisData *data) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File can't be opened\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(language, "javascript") == 0) {
            analyze_code(line, data);
        } else {
            printf("Language not supported.\n");
            break;
        }
    }
    fclose(file);
}
