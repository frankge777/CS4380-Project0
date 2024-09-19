Sure, here is a README file for your project:

---

# MyProject

This project converts a base-10 integer to its binary representation and includes unit tests using Google Test.


## Files

- **CMakeLists.txt**: Configures the project, including fetching and setting up Google Test.
- **main.cpp**: Main program that takes user input, validates it, and prints the binary representation.
- **myUFls.h**: Header file that declares the `convTen2Two` function.
- **myUFls.cpp**: Source file that defines the `convTen2Two` function.
- **mytest.cpp**: Contains the unit tests for the `convTen2Two` function using Google Test.

## Requirements

- CMake 3.10 or higher
- C++14 compatible compiler

## Building and Running

1. Clone the repository:
    ```sh
    git clone <repository_url>
    cd MyProject
    ```

2. Create a build directory and navigate into it:
    ```sh
    mkdir build
    cd build
    ```

3. Generate the build system using CMake:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    cmake --build .
    ```

5. Run the main program:
    ```sh
    ./main
    ```

## Running Tests

1. Ensure you have built the tests as part of the build process:
    ```sh
    cmake --build .
    ```

2. Run the tests:
    ```sh
    ctest
    ```

## Function Description

### convTen2Two

```cpp
string convTen2Two(unsigned int baseTenValue);
```

- **Input**: A non-negative base-10 integer.
- **Output**: A string representing the binary (base-2) equivalent of the input integer.
- **Example**:
  ```cpp
  convTen2Two(15); // Returns "1111"
  convTen2Two(1000); // Returns "1111101000"
  ```

## Example Usage

```sh
./main
Enter a non-negative base 10 integer between 0 and 4294967295 (with no commas) and hit Enter/Return:
15
1111
```

