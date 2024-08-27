
# Interactive Set Operations Program

## Project Overview

This project is an implementation of an interactive "pocket calculator" for performing operations on sets of integers. The program allows the user to execute various set operations through commands entered via standard input.

### Project Goals:
- Implement a memory-efficient set data structure using bitwise operations.
- Develop a program that can read, manipulate, and display sets based on user commands.
- Handle a wide range of input errors and provide detailed error messages.

## Key Project Files:
- `myset.c`: The main program file containing the `main` function and handling user interaction.
- `set.c`: Contains functions for performing operations on sets, such as union, intersection, subtraction, and symmetric difference.
- `set.h`: Header file defining the `set` data structure and function prototypes.

## Execution Steps:
1. **Compiling the Program**:
   - Use the provided `makefile` to compile the program with maximum warning flags enabled:
     ```bash
     make
     ```

2. **Running the Program**:
   - The program reads commands from standard input and performs operations on six predefined sets: `SETA`, `SETB`, `SETC`, `SETD`, `SETE`, `SETF`.
   - Commands include:
     - `read_set`: Populate a set with a list of integers.
     - `print_set`: Display the contents of a set.
     - `union_set`: Perform a union of two sets and store the result in a third set.
     - `intersect_set`: Perform an intersection of two sets and store the result in a third set.
     - `sub_set`: Subtract one set from another and store the result in a third set.
     - `symdiff_set`: Calculate the symmetric difference between two sets and store the result in a third set.
     - `stop`: Terminate the program.

3. **Handling Input Errors**:
   - The program is designed to detect and report various input errors, such as:
     - Undefined set names.
     - Invalid command names.
     - Values out of range.
     - Incorrect formatting of input.
   - After detecting an error, the program continues to prompt for new commands without halting.

4. **Testing**:
   - The `input` file provided contains a series of valid and invalid commands for testing purposes.
   - The program should be able to process the commands and produce the correct output, including error messages where applicable.

## Conclusion
This project demonstrates the implementation of a user-friendly program that performs set operations and robustly handles a variety of input errors. The use of bitwise operations ensures that the set data structure is memory-efficient and capable of handling large ranges of integers.

