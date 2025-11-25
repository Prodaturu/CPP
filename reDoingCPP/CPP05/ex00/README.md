# CPP05 - ex00: Bureaucrat Class

## Ex00 : Mommy, when I grow up, I want to be a bureaucrat!
- Exercise: 00  
- Turn-in directory: `ex00/`  
- Files to turn in: `Makefile`, `main.cpp`, `Bureaucrat.{h, hpp}`, `Bureaucrat.cpp`  
- Forbidden functions: None

Notes:
- Exception classes need not follow the Orthodox Canonical Form, but other classes must.
- Implement `Bureaucrat` with:
	- a constant name
	- a grade ranging from 1 (highest) to 150 (lowest)
- Constructing with invalid grade throws `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`.
- Provide `getName()` and `getGrade()`.
- Implement member functions to increment and decrement grade; throw exceptions on out-of-range.
- Overload `operator<<` to print: `<name>, bureaucrat grade <grade>.`
- Provide tests demonstrating expected behavior.

## Overview

This exercise introduces the **Bureaucrat** class, focusing on encapsulation, constructors, and exception handling in C++11. You will implement grade boundaries, custom exceptions, and proper class design patterns.

## Objectives

- Implement a `Bureaucrat` class with:
	- Private members: `_name` (const `std::string`), `_grade` (int)
	- Constructors, copy constructor, assignment operator, destructor
	- Getters: `getName() const`, `getGrade() const`
	- Methods: `incrementGrade()`, `decrementGrade()`
	- Custom exceptions: `GradeTooHighException`, `GradeTooLowException`
- Enforce grade limits (1-150) with exceptions
- Demonstrate usage and edge cases in `main.cpp`

## Requirements

- **C++11** standard: `-Wall -Wextra -Werror -std=c++11`
- Header guards: `#ifndef BUREAUCRAT_HPP`
- File naming: `Bureaucrat.hpp` / `Bureaucrat.cpp`
- Const correctness: getters and parameters
- Defensive programming: validate input, handle errors gracefully
- No exceptions outside Bureaucrat (subject requirement)
- Test scenarios in `main.cpp`

## Build Instructions

Use the provided Makefile:
```sh
make        # Build executable
make clean  # Remove .o files
make fclean # Remove .o files and executable
make re     # Full rebuild
make debug  # Build with debugging symbols
```

## Testing

- Test grade boundaries (1, 150, out-of-range)
- Test increment/decrement methods
- Check exception messages
- Use `valgrind --leak-check=full ./ex00` for memory leaks

## References

- [C++11 Standard](https://en.cppreference.com/w/cpp/language)
- [Exception Handling](https://en.cppreference.com/w/cpp/error/exception)
- [42 School Subject PDF](../subject.pdf)
