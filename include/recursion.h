#ifndef RECURSION_H
#define RECURSION_H
#include <stdbool.h>
#include "analyze.h"
bool is_function_called(const char *line, const char *function_name);
bool is_direct_recursion(const char *line, const char *function_name);
bool is_indirect_recursion(const char *line, const char *function_name, const char *called_function);
bool is_tail_recursive(const AnalysisData *data);
#endif
