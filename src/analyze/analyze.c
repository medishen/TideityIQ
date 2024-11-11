#include <stdio.h>
#include <string.h>
#include "../../include/analyze.h"
#include "../../include/utils.h"
#include "../../include/loops.h"
#include "../../include/recursion.h"
void analyze_code(const char *line, AnalysisData *data) {
    static const char *current_function = NULL;
     data->last_line = line;
    if (strstr(line, "function ")) {
        current_function = extract_function_name(line);
        data->current_function = current_function;
        data->functions++;
    }
    if (current_function != NULL) {
        if (is_direct_recursion(line, current_function)) {
            data->recursive_calls++;
        } else if (is_indirect_recursion(line, current_function, current_function)) {
            data->recursive_calls++;
        }
        if (strstr(line, "return")) {
            if (strstr(line, "<= 0") || strstr(line, "=== 0") || strstr(line, "<= n") || strstr(line, "!== 0")) {
                printf("Termination condition found in %s\n", current_function);
                data->current_function = current_function;
            }
        }

    }
    loop_analyze(line, data);
}
