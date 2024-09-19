# Base 10 to Base 2 Conversion Program

## Description
This program converts a non-negative base 10 integer between 0 and 4294967295 to its corresponding base 2 value. The program prompts the user for input, validates the input, performs the conversion, and prints the result.

## Requirements
- The program is written in C++.
- It performs base 10 to base 2 conversion for integers between 0 and 4294967295.
- It prompts the user for a non-negative base 10 integer.
- It validates the input and ensures it is properly formatted.
- It prints the corresponding base 2 value for valid input.
- The program exits with status 0 for valid input and status 1 for invalid input.
- The program consists of a single file: `main.cpp`.

## Validation
### Unit Tests
- Conversion function `convTen2Two` was tested with various inputs to ensure correct output:
  - Input: 0, Output: "0"
  - Input: 15, Output: "1111"
  - Input: 1000, Output: "1111101000"
  - Input: 4294967295, Output: "11111111111111111111111111111111"

### Manual Testing
- Tested with various valid inputs to ensure correct conversion:
  - Input: 0, Output: "0"
  - Input: 1, Output: "1"
  - Input: 2, Output: "10"
  - Input: 255, Output: "11111111"
  - Input: 4294967295, Output: "11111111111111111111111111111111"
- Tested with invalid inputs to ensure proper error handling:
  - Input: "abc", Output: "Invalid input!"
  - Input: "4294967296", Output: "Invalid input!"
  - Input: "-1", Output: "Invalid input!"
  - Input: "123,456", Output: "Invalid input!"

