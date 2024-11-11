#ifndef LOOPS_H
#define LOOPS_H
#include "analyze.h"
void loop_analyze(const char *line, AnalysisData *data);
bool is_mathematical_operation(const char *line);
bool is_end_of_scope(const char *line);
void analyze_code_complexity(const char *code[], size_t code_size, AnalysisData *data);
void print_complexity_results(const AnalysisData *data);

#endif