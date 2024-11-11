#include <stdbool.h>
#include <regex.h>
#include <string.h>
#include <stdio.h>
#include "../../include/analyze.h"
bool is_function_called(const char *line, const char *function_name) {
    char pattern[200];
    snprintf(pattern, sizeof(pattern), "\\b%s\\s*\\(", function_name);
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);
    int ret = regexec(&regex, line, 0, NULL, 0);
    regfree(&regex);
    return ret == 0;
}

bool is_direct_recursion(const char *line, const char *function_name) {
    return is_function_called(line, function_name);
}

bool is_indirect_recursion(const char *line, const char *function_name, const char *called_function) {
    return (is_function_called(line, called_function) && !is_function_called(line, function_name));
}

bool is_tail_recursive(const AnalysisData *data) {
    const char *function_name = data->current_function;
    const char *last_line = data->last_line;
    return (strstr(last_line, "return ") && strstr(last_line, function_name) != NULL);
}
