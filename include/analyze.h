#include <stdbool.h>
#ifndef ANALYZE_H
#define ANALYZE_H
// Data structure for storing analysis information
typedef struct {
    int functions;
    int nested_depth;
    int current_depth;
    int logarithmic_loops;
    int recursive_calls;
    const char *current_function;
    const char *last_line;
} AnalysisData;

// Function to analyze code and detect patterns
void analyze_code(const char *line, AnalysisData *data);
#endif 
