
# C++ Module 05: Repetition and Exceptions

## Overview

This module focuses on error handling, class design, canonical form, and basic inheritance with runtime polymorphism.
You will implement several classes representing bureaucrats and forms.
Forms have different signing and execution requirements, and bureaucrats interact with them.

The exercises gradually extend the system:

### ex00: Bureaucrat class (grades, exceptions, canonical form)

### ex01: Form class + interaction with Bureaucrat

### ex02: Abstract AForm + three concrete forms

### ex03: Intern class (factory for creating forms)

## C++ version: C++17

### Allowed headers:
- <iostream>
- <string>
- <exception>
- <fstream>
- <cstdlib>
- <ctime>

### Restrictions:
No STL containers unless explicitly needed.

## Phase Outcomes

- Establish proper technical and coding foundations
- Understand why and how AI can be dangerous during learning
- Develop problem-solving abilities through personal effort

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

**Directory:** `ex00/`  
**Files:** `Makefile`, `main.cpp`, `Bureaucrat.{hpp}`, `Bureaucrat.cpp`

### Assignment requirements:
Create a `Bureaucrat` class with:
- Constant name attribute
- Grade ranging from 1 (highest) to 150 (lowest)
- Getters: `getName()`, `getGrade()`
- Member functions: `incrementGrade()`, `decrementGrade()`
- Exceptions: `GradeTooHighException`, `GradeTooLowException`
- Overloaded `<<` operator: `<name>, bureaucrat grade <grade>.`

#### Attributes:
- constant `name`
- integer `grade`

#### Constructor and Destructor Constraints:
- Any attempt to create a `Bureaucrat` with an invalid grade must throw the appropriate exception.
	- Grade < 1: `GradeTooHighException`
	- Grade > 150: `GradeTooLowException`
- Copy constructor and assignment operator must be implemented.

#### Required Member Functions
- getName()
- getGrade()
- incrementGrade()
- decrementGrade()
- Overload `<<` operator for easy printing
	- (<name>, bureaucrat grade <grade>) (without angle brackets "<,>").

#### Exceptions
- `GradeTooHighException` and `GradeTooLowException`
- Must be catchable using try and catch blocks.
- This can be done by inheriting from `std::exception` and overriding the `what()` method.

## Exercise 01: Form up, maggots!

**Directory:** `ex01/`  
**Add Files:** `Form.{hpp}`, `Form.cpp`

Create a `Form` class with:
- Constant name, sign grade, execute grade
- Boolean signed status
- Getters and `<<` operator overload
- `beSigned(Bureaucrat const &)` member function
- Update `Bureaucrat::signForm()` to handle signing

## Exercise 02: No, you need form 28B, not 28C...

**Directory:** `ex02/`  
**Add Files:** `AForm.{hpp, cpp}`, concrete form classes

Rename `Form` to abstract `AForm` and create:
- `ShrubberyCreationForm` (sign 145, exec 137)
- `RobotomyRequestForm` (sign 72, exec 45)
- `PresidentialPardonForm` (sign 25, exec 5)

Add `execute()` member function to validate and execute forms.

## Exercise 03: At least this beats coffee-making

**Directory:** `ex03/`  
**Add Files:** `Intern.{hpp}`, `Intern.cpp`

Implement `Intern` class with `makeForm(std::string, std::string)` that returns appropriate `AForm*` pointers. Avoid excessive if/else structures.

## Compilation

Each exercise must include a `Makefile` that compiles the code into an executable named after the exercise directory (e.g., `ex00`, `ex01`, etc.). The `Makefile` should include rules for `all`, `clean`, `fclean`, and `re`.

## Testing

Each exercise should include a `main.cpp` file demonstrating the functionality of the implemented classes and methods.
The provided `main.cpp` files will be used for testing your implementation.

## Submission
Submit the entire module directory, including all exercise subdirectories and their contents.

## Evaluation Criteria
- Correctness and completeness of implementation
- Proper use of exceptions and error handling
- Adherence to C++ best practices and coding standards
- Quality and clarity of code (comments, naming conventions, etc.)
- Successful compilation and execution of provided test cases

## Notes
- Focus on understanding the concepts rather than just completing the tasks.
- Ensure your code is well-documented and follows good coding practices.
- Test your code thoroughly to handle edge cases and exceptions.
- Collaboration is encouraged, but all submitted work must be your own.
- Seek help from instructors or peers if you encounter difficulties.
Good luck and happy coding!

### Module Author: OpenAI's ChatGPT



