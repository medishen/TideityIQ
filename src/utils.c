#include <stdio.h>
#include <string.h>
char *get_lang(char *filename){
   char *extension = strrchr(filename, '.');
    if (!extension) {
        return "unknown";
    }
    if (strcmp(extension, ".js") == 0) {
        return "javascript";  // Return lowercase
    } else if (strcmp(extension, ".py") == 0) {
        return "python";  // Return lowercase
    } else if (strcmp(extension, ".c") == 0) {
        return "c";  // Return lowercase
    } else {
        return "unknown";
    }
}
const char* extract_function_name(const char* line) {
    static char func_name[256];
    const char* start = strstr(line, "function ");
    if (start) {
        start += 9; // Skip past "function "
        const char* end = strchr(start, '(');
        if (end) {
            size_t len = end - start;
            strncpy(func_name, start, len);
            func_name[len] = '\0';
            return func_name;
        }
    }
    return NULL;
}
void print_output(const char *big_o, const char *theta, const char *omega, const char *explanation) {
    printf("Big O Complexity: %s\n", big_o);
    printf("Theta Complexity: %s\n", theta);
    printf("Omega Complexity: %s\n", omega);
    printf("Explanation: %s\n", explanation);
}