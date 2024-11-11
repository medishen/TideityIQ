#include <stdio.h>
#include <string.h>
#include "loops.h"

void loop_analyze(const char *line, AnalysisData *data) {
    // Check for basic loop types in JavaScript and update depth
    if (strstr(line, "for ") || strstr(line, "while ") || strstr(line, "do ") || strstr(line, ".forEach") || strstr(line, ".map")) {
        data->current_depth++;
       if (data->current_depth > data->nested_depth) {
            data->nested_depth = data->current_depth;
        }

        // Analyze for loop, which could be linear or logarithmic
        if (strstr(line, "for (")) {
            // Detecting a logarithmic pattern, e.g., i *= 2
            if ((strstr(line, "i *= 2") || strstr(line, "i = i * 2") || strstr(line, "i /= 2") || strstr(line, "i = i / 2"))) {
                data->logarithmic_loops++;
            }
        }
        if (strstr(line, "while (")) {
            if (strstr(line, "i *= 2") || strstr(line, "i /= 2") || strstr(line, "<=")) {
                data->logarithmic_loops++;
            }
        }
    }
    if (strstr(line, "if (")) {
        if (data->current_depth > data->nested_depth) {
            data->nested_depth = data->current_depth;
            data->logarithmic_loops++;
        }
    }

    if (strstr(line, "}")) {
        if (data->current_depth > 0) {
            data->current_depth--;
        }
    }
}