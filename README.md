## Project Overview

This project implements a simple C++ program that converts a base-10 (decimal) integer to a base-2 (binary) string representation. The user is prompted to input a non-negative base-10 integer between `0` and `4294967295`, and the program outputs the corresponding binary representation.

### Components

1. **`myUFls.h`**: This header file contains the declaration of the function `convTen2Two` which converts a base-10 integer to its binary (base-2) string representation.
2. **`myUFls.cpp`**: This source file defines the function `convTen2Two`.
3. **`main.cpp`**: This is the main program that interacts with the user, accepts input, and calls the `convTen2Two` function to display the binary output.
4. **Makefile**: Automates the compilation of the project, creating an executable called `main`. It also includes a clean command to remove compiled object files.

## How to Build

### Requirements

- A C++ compiler (e.g., `g++`).
- A UNIX-like environment or terminal (for `Makefile`).

### Compilation

To compile the project, run the following command in the terminal:

```bash
make
```

This will compile the source files and create an executable named `main`.

### Running the Program

After compiling, run the program with the following command:

```bash
./main
```

The program will prompt you to input a non-negative base-10 integer between `0` and `4294967295` (without commas). The output will be the binary representation of the input integer.

Example:

```
Enter a non-negaFve base 10 integer between 0 and 4294967295 (with no commas) and hit Enter/Return:
10
1010
```

### Cleaning the Build

To remove the compiled object files and the executable, use the `clean` target:

```bash
make clean
```

This will delete all object files (`*.o`) and the `main` executable.

## Function Description

- **`convTen2Two`**: 
  - **Input**: A non-negative unsigned integer (`unsigned int`).
  - **Output**: A string representing the binary equivalent of the input integer.
  - **Description**: This function converts the given base-10 integer into a binary string by repeatedly dividing the number by 2 and recording the remainder. The binary string is then reversed to give the correct binary representation.


