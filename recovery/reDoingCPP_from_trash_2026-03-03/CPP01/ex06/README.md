# ex06 - Harl Filter

## Description

This exercise introduces a simple logging filter using C++ classes. The program simulates a complaint system with different log levels: DEBUG, INFO, WARNING, and ERROR. Based on the input, it displays messages corresponding to the selected level and higher severity levels.

## Instructions

- Implement a `Harl` class with a method to filter and display messages based on the provided log level.
- Accept the log level as a command-line argument.
- Only display messages for the specified level and all levels above it.

## Compilation

Compile the program using:

```bash
g++ -std=c++11 -Wall -Wextra -Werror main.cpp Harl.cpp -o harlFilter
```

## Usage

Run the program with a log level argument:

```bash
./harlFilter WARNING
```

## Notes

- Handle invalid or missing arguments gracefully.
- Follow 42 coding standards and best practices.
- Test with all log levels to ensure correct filtering.
