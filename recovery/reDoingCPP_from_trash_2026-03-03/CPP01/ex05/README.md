# CPP01 - ex05: Harl 2.0

## Overview

This exercise introduces the `Harl` class, which automates Harl's complaints based on different log levels. The goal is to use pointers to member functions to select the appropriate complaint method, avoiding complex conditional statements.

## Requirements

- **Class:** `Harl`
	- **Private Methods:**
		- `void debug(void);`
		- `void info(void);`
		- `void warning(void);`
		- `void error(void);`
	- **Public Method:**
		- `void complain(std::string level);`
			- Calls the appropriate private method based on the `level` parameter.

- **Implementation Constraints:**
	- Use pointers to member functions for method selection.
	- Avoid using multiple `if/else if/else` statements.

## Log Levels & Example Messages

- **DEBUG:**  
	`"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"`

- **INFO:**  
	`"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"`

- **WARNING:**  
	`"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."`

- **ERROR:**  
	`"This is unacceptable! I want to speak to the manager now."`

## Files to Submit

- `Makefile`
- `main.cpp`
- `Harl.h` or `Harl.hpp`
- `Harl.cpp`

## Testing

Provide tests in `main.cpp` to demonstrate Harl's complaints for each log level. You may use the example messages above or your own.

## Notes

- No forbidden functions.
- Focus on pointers to member functions for clean and efficient code.
- Ensure your implementation is modular and easy to test.
