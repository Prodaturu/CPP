# C++ - Module 05
Repetition and Exceptions

## Summary
This document contains the exercises of Module 05 from the C++ modules.  
Version: 17.0

## Contents
- I Introduction
- II General rules
- III AI Instructions
- IV Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
- V Exercise 01: Form up, maggots!
- VI Exercise 02: No, you need form 28B, not 28C...
- VII Exercise 03: At least this beats coffee-making
- VIII Submission and Peer Evaluation

---

## I Introduction
C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes" (source: Wikipedia).  
The goal of these modules is to introduce you to Object-Oriented Programming. This will be the starting point of your C++ journey. Many languages are recommended for learning OOP. We have chosen C++ since it is derived from your old friend, C.

Because this is a complex language, and in order to keep things simple, your code will comply with the C++11 standard.

We are aware that modern C++ is significantly different in many aspects. If you want to become a proficient C++ developer, it is up to you to go further after the 42 Common Core!

---

## II General rules

### Compiling
- Compile your code with `c++` and the flags `-Wall -Wextra -Werror`.
- Your code should still compile if you add the flag `-std=c++11`.

### Formatting and naming conventions
- Exercise directories: `ex00`, `ex01`, ..., `exn`.
- Name files, classes, functions, member functions and attributes as required in the guidelines.
- Write class names in UpperCamelCase. Files containing class code will be named according to the class name, e.g. `ClassName.hpp`, `ClassName.cpp`.
- Every output message must end with a newline character and be displayed to standard output (unless specified otherwise).
- No enforced coding style, but write clean and readable code for peer evaluators.

### Allowed / Forbidden
- You are allowed to use almost everything from the standard library; prefer C++-style equivalents where possible.
- External libraries are forbidden. C++17 (and derived forms beyond what's allowed by the project) and Boost are forbidden if explicitly restricted by exercise. The following C functions are forbidden if specified in exercises: `*printf()`, `*alloc()`, and `free()`.
- Unless explicitly allowed, `using namespace <ns_name>` and `friend` keywords are forbidden.
- STL usage: note that the original curriculum restricts containers/algorithms until specified modules; follow the module-specific rules (e.g., no `vector`, `list`, `map`, or `<algorithm>` when disallowed).

### Design requirements
- Avoid memory leaks when using dynamic allocation (`new` / `delete`).
- From Module 02 to Module 09, classes must follow the Orthodox Canonical Form unless otherwise specified.
- Do not implement non-template functions in header files; doing so leads to a failing grade for the exercise.
- Headers must be usable independently and include their dependencies; prevent double inclusion with include guards.

### Read me
- You may add files to split code, but turn in mandatory files.
- Examples may show requirements not explicitly written—read everything.
- Read each module completely before starting.

Regarding the Makefile, follow the same rules as in C projects (see the Norm chapter about the Makefile). You will implement many classes; scripting your editor may help.

You are given freedom to complete the exercises but follow mandatory rules and read the documentation.

---

## III AI Instructions

### Context
This project helps you discover core ICT training building blocks. To properly anchor key knowledge and skills, adopt a thoughtful approach to using AI tools and support. True foundational learning requires genuine intellectual effort — through challenge, repetition, and peer-learning exchanges.

### Main message
- Build strong foundations without shortcuts.
- Develop technical and problem-solving skills.
- Experience real peer-learning.
- The learning journey is more important than the result.
- Learn about AI risks and develop control practices and countermeasures.

### Learner rules
- Apply reasoning to assigned tasks before turning to AI.
- Do not ask for direct answers from AI.
- Learn about the institution's global approach to AI.

### Phase outcomes
- Get proper tech and coding foundations.
- Know why and how AI can be dangerous during this phase.

### Comments and examples
- AI can solve projects, but relying on it prevents building your own reasoning.
- Peer learning exposes you to different approaches and prepares you for evaluations without AI.
- AI is part of the curriculum as both a tool and a subject. Follow the documentation available on the intranet.

Good practice example: ask a peer and discuss approaches for 10 minutes to gain understanding.  
Bad practice example: secretly use AI to copy code, fail to explain it during peer evaluation, and fail exams without AI.

---

## IV Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
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

---

## V Exercise 01: Form up, maggots!
- Exercise: 01  
- Turn-in directory: `ex01/`  
- Files to turn in: Files from previous exercise + `Form.{h, hpp}`, `Form.cpp`  
- Forbidden functions: None

Notes:
- Implement `Form` with:
	- constant name
	- boolean `isSigned` (false at construction)
	- constant grade required to sign
	- constant grade required to execute
- Grades use same 1..150 bounds; invalid grades throw `Form::GradeTooHighException` or `Form::GradeTooLowException`.
- All attributes are private. Provide getters and an `operator<<` to print form info.
- Add `beSigned(Bureaucrat const&)` to set signed status if bureaucrat grade is high enough; otherwise throw `Form::GradeTooLowException`.
- Modify `Bureaucrat::signForm()` to call `Form::beSigned()` and print success/failure messages:
	- "<bureaucrat> signed <form>"
	- "<bureaucrat> couldn't sign <form> because <reason>."
- Add tests.

---

## VI Exercise 02: No, you need form 28B, not 28C...
- Exercise: 02  
- Turn-in directory: `ex02/`  
- Files to turn in: `Makefile`, `main.cpp`, `Bureaucrat.{h,hpp,cpp}`, `AForm.{h,hpp,cpp}`, `ShrubberyCreationForm.{h,hpp,cpp}`, `RobotomyRequestForm.{h,hpp,cpp}`, `PresidentialPardonForm.{h,hpp,cpp}`  
- Forbidden functions: None

Notes:
- Rename `Form` to abstract base `AForm`. Keep attributes private in base class.
- Implement concrete forms:
	- ShrubberyCreationForm: sign 145, exec 137 — creates `<target>_shrubbery` and writes ASCII trees.
	- RobotomyRequestForm: sign 72, exec 45 — 50% chance of successful robotomy; otherwise failure.
	- PresidentialPardonForm: sign 25, exec 5 — announces a presidential pardon.
- Each concrete class takes a single `target` parameter in constructor.
- Add `execute(Bureaucrat const & executor) const` in base class and implement concrete actions. Check signed status and executor grade; throw appropriate exceptions on failure.
- Add `Bureaucrat::executeForm(AForm const & form) const` to attempt execution and print success or explicit error messages.
- Add tests.

---

## VII Exercise 03: At least this beats coffee-making
- Exercise: 03  
- Turn-in directory: `ex03/`  
- Files to turn in: Files from previous exercises + `Intern.{h,hpp}`, `Intern.cpp`  
- Forbidden functions: None

Notes:
- Implement `Intern` with `makeForm(std::string const & name, std::string const & target)` returning `AForm*`.
- `makeForm` should construct and return the appropriate concrete `AForm` (with target set) and print:
	- "Intern creates <form>"
- If the form name is unknown, print an explicit error message.
- Avoid excessive if/else chains; prefer a clean, maintainable solution.
- Example:
	- `Intern someRandomIntern; AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");`

---

## VIII Submission and Peer Evaluation
- Submit your assignment to your Git repository.
- Only work inside your repository will be evaluated.
- Double-check folder and file names.
- A minor modification may be requested during evaluation to verify understanding—be prepared to make small changes quickly.

--- 

Notes: follow exercise-specific constraints (headers, forbidden functions, grade bounds, memory management, canonical form) and include tests demonstrating behavior.
