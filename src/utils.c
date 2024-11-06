#include <stdio.h>
#include <string.h>
#include "../include/utils.h"

char *get_lang(char *filename){
    char *extension = strrchr(filename, '.');
    if (!extension) {
        return "unknown";
    }
    if (strcmp(extension, ".js") == 0) {
        return "JavaScript";
    } else if (strcmp(extension, ".py") == 0) {
        return "Python";
    } else if (strcmp(extension, ".c") == 0) {
        return "C";
    } else {
        return "unknown";
    }
}