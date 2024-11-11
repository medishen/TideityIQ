#include <stdio.h>
#include "../../include/utils.h"
#include "../../include/analyze.h"
#include "../../include/recursion.h"

void calculate_complexity(const AnalysisData *data) {
    printf("\nComplexity Analysis:\n");
    
    // Handle logarithmic loop structure (O(log n))
    if (data->logarithmic_loops > 0 && data->nested_depth == 1) {
        print_output("O(log n)", "Θ(log n)", "Ω(1)","Logarithmic complexity due to loop with halving or logarithmic reduction (e.g., binary search).");
        return;
    }

    // Handle simple linear complexity (O(n))
    if (data->nested_depth == 1 && data->logarithmic_loops == 0) {
        print_output("O(n)", "Θ(n)", "Ω(1)", "Linear complexity due to single loop traversing the entire input.");
        return;
    }

    // Handle n log n complexity (for two-level nested loops with logarithmic behavior)
    if (data->nested_depth == 2 && data->logarithmic_loops > 0) {
        print_output("O(n log n)", "Θ(n log n)", "Ω(log n)", "n log n complexity due to nested loops with logarithmic reduction.");
        return;
    }

    // Handle quadratic complexity (O(n^2)) for two-level nested loops
    if (data->nested_depth == 2 && data->logarithmic_loops == 0) {
        print_output("O(n^2)", "Θ(n^2)", "Ω(n)", "Quadratic complexity due to two-level nested loops.");
        return;
    }

    // Handle polynomial complexity for higher nested depths (e.g., O(n^3), O(n^4), etc.)
    if (data->nested_depth > 2) {
        char big_o[50], theta[50], omega[50];
        sprintf(big_o, "O(n^%d)", data->nested_depth);
        sprintf(theta, "Θ(n^%d)", data->nested_depth);
        sprintf(omega, "Ω(n^(%d-1))", data->nested_depth);
        char explanation[100];
        sprintf(explanation, "Polynomial complexity due to %d-level nested loops.", data->nested_depth);
        print_output(big_o, theta, omega, explanation);
    }

    // Handle recursion complexity analysis
    if (data->recursive_calls > 0) {
        printf("Detected recursive function calls.\n");
        // Handle linear recursion (e.g., recursion on a single branch with reduced input)
        printf("nested_depth: %d\n",data->nested_depth);
        printf("Recursive Calls: %d\n", data->recursive_calls);
        printf("Logarithmic Loops: %d\n", data->logarithmic_loops);
        // Logarithmic Recursion: Single recursive call with logarithmic reduction
       if (data->recursive_calls == 1 && data->logarithmic_loops > 0) {
            print_output(
                "O(log n)",
                "Θ(log n)",
                "Ω(1)",
                "Logarithmic recursion detected, with input size halving in each call."
            );
        }
        // Linear Recursion: Single recursive call with constant reduction
        else if (data->recursive_calls == 1 && data->logarithmic_loops == 0) {
            print_output(
                "O(n)",
                "Θ(n)",
                "Ω(1)",
                "Linear recursion with constant reduction in each call."
            );
        }
        // Divide-and-Conquer Recursion: Multiple calls with logarithmic reduction
        else if (data->recursive_calls > 1 && data->logarithmic_loops > 0) {
            print_output(
                "O(n log n)",
                "Θ(n log n)",
                "Ω(1)",
                "Divide-and-conquer recursion detected, characteristic of algorithms like merge sort."
            );
        }
        // Exponential Recursion: Multiple branching recursive calls without input reduction
        else if (data->recursive_calls > 1 && data->logarithmic_loops == 0) {
            print_output(
                "O(2^n)",
                "Θ(2^n)",
                "Ω(1)",
                "Exponential recursion detected due to branching recursive calls without reduction."
            );
        }
        // Tail Recursion: Optimize to O(n) if detected
        if (is_tail_recursive(data)) {
            print_output(
                "O(n)",
                "Θ(n)",
                "Ω(1)",
                "Tail recursion detected, may be optimized to linear complexity."
            );
        }
    }

     // If no specific pattern is detected, report as unknown complexity
    if (data->logarithmic_loops == 0 && data->nested_depth == 0 && data->recursive_calls == 0) {
        print_output(
            "Unknown",
            "Unknown",
            "Unknown",
            "No specific pattern detected. Unable to determine complexity based on current analysis."
        );
    }
}
