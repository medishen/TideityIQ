#include <stdio.h>
#include <stdlib.h>
char *read_file(const char *filename) {
    FILE *fptr;
    char *content;
    long file_size;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("file can't be opened \n");
        return NULL;
    }
    fseek(fptr, 0, SEEK_END);
    file_size = ftell(fptr);
    rewind(fptr);
    content = (char *)malloc((file_size + 1) * sizeof(char));
    if (content == NULL) {
        printf("Memory allocation failed\n");
        fclose(fptr);
        return NULL;
    }
    fread(content, sizeof(char), file_size, fptr);
    content[file_size] = '\0'; 
    fclose(fptr);
    return content;
}
