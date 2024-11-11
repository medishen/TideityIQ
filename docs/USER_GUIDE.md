## User Guide for TideityIQ

### Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Examples](#examples)
5. [Troubleshooting](#troubleshooting)

### 1. Introduction

TideityIQ (`tdq`) is a command-line tool designed for analyzing JavaScript code to determine the time complexity of recursive functions. The tool supports analyzing files with `.js` extensions and provides detailed output, including Big O, Theta, and Omega notations.

### 2. Installation

#### 2.1 Prerequisites

Before installing TideityIQ, ensure that you have the following installed on your system:

- **GCC**: The GNU Compiler Collection for compiling C code.
- **Docker** (optional): For running the tool inside a container.
- **Make**: For building the project.

#### 2.2 Manual Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/medishen/TideityIQ.git
   cd TideityIQ
   ```

2. Build the project:

   ```bash
   make
   ```

3. Install the tool to your system:

   ```bash
   sudo make install
   ```

4. You can now run the tool using the command `tdq`.

#### 2.3 Docker Installation (Optional)

If you prefer using Docker, pull the pre-built Docker image:

```bash
docker pull bitsgenix/tdq
```

You can then run the tool inside a Docker container:

```bash
docker run tdq ./hello.js
```

### 3. Usage

#### 3.1 Basic Usage

To analyze a JavaScript file, simply run:

```bash
tdq <path_to_your_file>.js
```

If no file is provided, the tool will display a welcome message and description.

#### 3.2 Example

Here’s an example of how to analyze a file `hello.js`:

```bash
tdq hello.js
```

**Output:**

```text
Complexity Analysis:
Detected recursive function calls.
nested_depth: 0
Recursive Calls: 2
Logarithmic Loops: 0
Big O Complexity: O(2^n)
Theta Complexity: Θ(2^n)
Omega Complexity: Ω(1)
Explanation: Exponential recursion detected due to branching recursive calls without reduction.
```

#### 3.3 Running the Tool without Arguments

If you run the tool with no arguments:

```bash
tdq
```

The tool will display a welcome message with an introductory animation.

### 4. Examples

#### 4.1 Fibonacci Function Example

For the following `hello.js` file:

```javascript
function fibonacci(n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
```

Running `tdq hello.js` will analyze the recursion and print:

```text
Complexity Analysis:
Detected recursive function calls.
nested_depth: 0
Recursive Calls: 2
Logarithmic Loops: 0
Big O Complexity: O(2^n)
Theta Complexity: Θ(2^n)
Omega Complexity: Ω(1)
Explanation: Exponential recursion detected due to branching recursive calls without reduction.
```

### 5. Troubleshooting

#### 5.1 Unsupported File Type

If you receive an error about an unsupported file type, ensure that your file is a `.js` JavaScript file. Currently, the tool only supports JavaScript files.

#### 5.2 Command Not Found

If you get an error like `command not found`, ensure the tool is installed correctly and that `/usr/local/bin` is in your system's PATH.
