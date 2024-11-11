#ifndef UTILS_H
#define UTILS_H

char *get_lang(char *filename);
const char* extract_function_name(const char* line);
void print_output(const char *big_o, const char *theta, const char *omega, const char *explanation);

#endif
