## Software Requirements Specification (SRS) for TideityIQ

### 1. Introduction

#### 1.1 Purpose

The purpose of **TideityIQ** (tdq) is to analyze JavaScript functions, specifically recursive functions, and determine their time complexity based on various characteristics like recursion depth, loop types, and overall complexity. This tool helps developers understand the performance of their code by analyzing recursion, loops, and other structural components.

#### 1.2 Scope

TideityIQ analyzes JavaScript files (`.js`) to detect recursive function calls and estimate time complexities (Big O, Theta, and Omega notations). It supports detailed reporting and provides an interactive terminal-based user experience.

#### 1.3 Intended Audience

- **Software Developers**: Particularly those dealing with recursive functions and performance optimization.
- **Students**: Learning about time complexity analysis and recursion.
- **Researchers**: Evaluating the time complexity of JavaScript functions in academic or practical settings.

#### 1.4 Definitions, Acronyms, and Abbreviations

- **tdq**: The command-line tool that initiates the analysis process.
- **Big O Notation**: Used to describe the upper bound of an algorithm’s running time.
- **Theta Notation**: Describes the tight bound of an algorithm’s running time.
- **Omega Notation**: Describes the lower bound of an algorithm’s running time.
- **Recursion**: A function calling itself to solve smaller instances of the problem.

#### 1.5 References

- JavaScript language specification.
- Big-O notation reference: https://bigocheatsheet.com.

### 2. Functional Requirements

#### 2.1 User Requirements

- The tool must analyze JavaScript files for recursive function patterns and detect loops.
- The user must be able to run the tool via the command line by typing `tdq` followed by the JavaScript file path.
- The tool must display a report with time complexity analysis, including:
  - Nested Depth
  - Recursive Calls
  - Logarithmic Loops
  - Big O, Theta, and Omega Complexity
  - Detailed Explanation

#### 2.2 Functional Requirements

- **Command Line Interface (CLI)**: The tool should accept the following:
  - **No argument**: Displays a welcome message and description.
  - **JavaScript file as argument**: Analyzes the file and prints the time complexity analysis.
- **Recursion Detection**: The tool should identify recursive functions and estimate their time complexity using Big O notation.

- **Complexity Calculation**: The tool must calculate Big O, Theta, and Omega complexities for recursive calls and loops.

- **Interactive Terminal Output**: The tool must use a typewriter effect to display text with a delay for an engaging user experience.

#### 2.3 System Features

- **File Analysis**: The system must parse the JavaScript file and detect recursive functions.
- **Display of Analysis**: After analyzing the file, the system must display a report with the detected time complexity and a detailed explanation.
- **Script Execution**: If no arguments are passed, the tool will execute a script (`bash ./bin/tdq`) that provides introductory information.
- **Error Handling**: If an unsupported file type is passed, the system will notify the user.

### 3. Non-Functional Requirements

#### 3.1 Performance Requirements

- The tool must process JavaScript files efficiently, even for relatively large codebases.
- The complexity analysis must be accurate and executed within reasonable time limits, typically under 10 seconds for small files.

#### 3.2 Usability

- The tool should be easy to use, with clear messages guiding the user through each step.
- It should provide helpful error messages if a file is unsupported or if there are issues with the input.

#### 3.3 Reliability

- The tool should handle a variety of JavaScript code structures, including simple and complex recursive functions.
- The system should produce consistent and accurate results when the same file is analyzed multiple times.

### 4. System Design

#### 4.1 Architecture

The system consists of the following components:

1. **Main Program**: Analyzes the JavaScript file, detects recursion, and calculates time complexities.
2. **Script for Intro**: Displays a welcome message and instructions when no file is provided.
3. **Analysis Module**: Contains logic for detecting recursion and calculating time complexity.
4. **Output Formatting**: Displays results in an engaging, readable format using a typewriter effect.

#### 4.2 Dependencies

- **GCC** (GNU Compiler Collection) for compiling C source code.
- **Make** for automating the build process.
- **Bash** for running the interactive script and displaying outputs.
