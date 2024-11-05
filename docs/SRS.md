# Software Requirements Specification (SRS) for TideityIQ

## 1. Introduction

### 1.1 Purpose

The purpose of the **TideityIQ** project is to develop a command-line interface (CLI) tool that analyzes algorithmic complexity of code snippets provided by users in multiple programming languages (initially JavaScript, Python, and C). The tool will compute and display the complexity in Big O, Theta, and Omega notations, helping users understand the performance characteristics of their algorithms.

### 1.2 Scope

The scope of the TideityIQ project includes:

- Parsing code snippets written in JavaScript, Python, and C.
- Analyzing the complexity of the provided algorithms.
- Presenting the complexity results in a clear and understandable format.
- Providing a user-friendly CLI for interaction.
- Delivering example codes and documentation for ease of use.

### 1.3 Definitions, Acronyms, and Abbreviations

- **CLI**: Command-Line Interface
- **Big O**: An asymptotic notation that describes the upper limit of the runtime of an algorithm.
- **Theta**: An asymptotic notation that describes a tight bound on the runtime of an algorithm.
- **Omega**: An asymptotic notation that describes the lower limit of the runtime of an algorithm.
- **SRS**: Software Requirements Specification

## 2. Overall Description

### 2.1 Product Perspective

TideityIQ will be a standalone CLI tool that provides algorithm analysis capabilities. It will not rely on external libraries for algorithm complexity analysis but will implement the necessary algorithms and parsing mechanisms directly in C. The tool will be designed to be intuitive, allowing users to input their code easily and receive meaningful feedback on its complexity.

### 2.2 Product Functions

The main functions of the TideityIQ tool include:

1. **Code Input**: Allow users to input code snippets in supported programming languages.
2. **Code Parsing**: Analyze and parse the input code to identify algorithms and data structures.
3. **Complexity Analysis**: Calculate the complexity (Big O, Theta, Omega) of the analyzed code.
4. **Result Output**: Present the complexity results clearly, including a brief explanation of the results.
5. **Examples and Documentation**: Provide example codes and detailed documentation for users.

### 2.3 User Classes and Characteristics

- **Students and Educators**: Users who are learning algorithms and want to understand the complexities of their implementations.
- **Developers**: Software developers who need to analyze and optimize their code for better performance.
- **Researchers**: Individuals who study algorithm performance and require tools for analysis.

### 2.4 Operating Environment

TideityIQ will operate in a command-line environment, compatible with:

- Windows (via Command Prompt or PowerShell)
- macOS (via Terminal)
- Linux (via Terminal)

### 2.5 Design and Implementation Constraints

- The tool will be implemented in the C programming language.
- It will initially support three programming languages: JavaScript, Python, and C.
- The project will not use external libraries for parsing or analysis, focusing instead on custom implementations.

### 2.6 Assumptions and Dependencies

- Users will have a basic understanding of algorithm complexity.
- Users have the necessary runtime environment to compile and run C programs.
- The tool's functionality may depend on the correctness and clarity of the provided code snippets.

## 3. Specific Requirements

### 3.1 Functional Requirements

#### 3.1.1 Code Input

- The system shall accept code snippets through the command line.
- The user shall specify the programming language of the input code.

#### 3.1.2 Code Parsing

- The system shall correctly identify and parse functions, loops, and conditional statements in the provided code.
- The system shall support syntax highlighting for better readability.

#### 3.1.3 Complexity Analysis

- The system shall calculate the complexity of the provided code and output the following:
  - Big O notation
  - Theta notation
  - Omega notation

#### 3.1.4 Result Output

- The system shall display the calculated complexities along with a brief explanation for each notation.
- The output format shall be user-friendly and easy to understand.

#### 3.1.5 Examples and Documentation

- The system shall include example code snippets demonstrating various algorithms.
- The documentation shall explain how to use the tool, input formats, and example outputs.

### 3.2 Non-Functional Requirements

#### 3.2.1 Performance

- The tool shall analyze code snippets and produce results within a reasonable time frame (less than 5 seconds for code snippets of average length).

#### 3.2.2 Usability

- The CLI interface shall be intuitive, with clear instructions and feedback.
- Error messages shall be informative and guide the user to correct input issues.

#### 3.2.3 Reliability

- The tool shall be robust and handle various edge cases without crashing.
- The parser shall correctly identify and manage common programming errors in the input code.

#### 3.2.4 Portability

- The application shall compile and run on different operating systems (Windows, macOS, and Linux).

#### 3.2.5 Maintainability

- The code shall be well-structured, documented, and modular to facilitate future enhancements and maintenance.

## 4. Use Cases

### 4.1 Use Case: Analyze Code Complexity

**Actor**: User (Student/Developer)

**Precondition**: The user has installed the TideityIQ tool and has access to a command-line interface.

**Main Flow**:

1. The user runs the TideityIQ tool from the command line.
2. The user inputs a code snippet and specifies the programming language.
3. The system parses the code and analyzes its complexity.
4. The system outputs the complexities in Big O, Theta, and Omega notations with explanations.

**Postcondition**: The user receives the analysis results and can use the information to improve their code.

### 4.2 Use Case: Provide Example Code

**Actor**: User

**Precondition**: The user is interacting with the TideityIQ tool.

**Main Flow**:

1. The user requests example code snippets.
2. The system displays a selection of example algorithms and their complexities.

**Postcondition**: The user can reference example code to understand algorithmic complexity better.

## 5. External Interface Requirements

### 5.1 User Interfaces

- The CLI shall be the primary user interface for the TideityIQ tool.
- The interface shall support input prompts and output displays.

### 5.2 Hardware Interfaces

- The tool shall run on any machine with a C compiler and a command-line interface.

### 5.3 Software Interfaces

- The tool shall interface with the operating system to handle file input/output and execute commands.

## 6. Future Considerations

Future versions of TideityIQ may expand support to include additional programming languages, integrate advanced features like graphical representations of complexity, or provide more extensive user guidance through interactive tutorials.
