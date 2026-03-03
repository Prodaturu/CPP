# Exercise 04: Sed is for losers

## Overview

This exercise requires you to implement a simple text replacement utility in C++. The program mimics the behavior of the Unix `sed` command by replacing all occurrences of a given string (`s1`) with another string (`s2`) in a specified file.

## Requirements

- **Input:** The program takes three parameters:
	1. `filename` - the name of the input file
	2. `s1` - the string to be replaced
	3. `s2` - the string to replace with
- **Output:** The program creates a new file named `<filename>.replace` containing the modified content.
- **Restrictions:**
	- Do **not** use C file manipulation functions.
	- Do **not** use `std::string::replace`.
	- All other `std::string` member functions are allowed.
- **Error Handling:** The program must handle unexpected inputs and errors gracefully.
- **Testing:** You must provide your own tests to verify correctness.

## Implementation

- The program reads the entire content of the input file using C++ streams.
- It searches for all occurrences of `s1` and replaces them with `s2` using allowed `std::string` functions (e.g., `find`, `substr`, `append`).
- The modified content is written to `<filename>.replace`.
- Proper error messages are displayed for invalid arguments, file access issues, or other failures.

## Files to Submit

- `Makefile`
- `main.cpp`
- Any additional `.cpp` and `.h`/`.hpp` files

## Usage

```bash
./sed_is_for_losers <filename> <s1> <s2>
```

## Example

Suppose `input.txt` contains:
```
hello world
hello universe
```
Running:
```bash
./sed_is_for_losers input.txt hello hi
```
Creates `input.txt.replace` with:
```
hi world
hi universe
```

## Notes

- Ensure your implementation does not use forbidden functions.
- Include comprehensive tests to demonstrate correct behavior.
- Handle all edge cases, such as empty strings and missing files.


## Requirements 
- **Language**: C++11
- **Compiler**: c++ with flags `-Wall -Wextra -Werror -std=c++11`

- **Executable**: `sed_is_for_losers`

- **Makefile Targets**:
  - `all`: Compile the program
  - `clean`: Remove object files
  - `fclean`: Remove object files and the executable
  - `re`: Recompile the program from scratch
