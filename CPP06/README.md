# C++ - Module 06
C++ casts

## Summary
This module focuses on explicit type conversion and runtime type identification in C++98.

Exercises:
- `ex00`: Conversion of scalar types
- `ex01`: Serialization
- `ex02`: Identify real type

## General Rules (Subject)
- Compile with `c++ -Wall -Wextra -Werror`.
- Code must also compile with `-std=c++98`.
- Required exercise directories are `ex00`, `ex01`, `ex02`.
- Class naming: `UpperCamelCase`; files named after classes.
- Avoid memory leaks.
- From Module 02 onward, use Orthodox Canonical Form unless the subject says otherwise.
- No function implementations in headers (except templates).
- Headers must be self-sufficient and protected with include guards.

## Additional Rule for This Module
For each exercise, conversions must use the appropriate C++ cast type.
This point is checked during evaluation.

## ex00 - Conversion of Scalar Types
Turn-in files:
- `Makefile`
- `*.cpp`
- `*.hpp` / `*.h`

Goal:
- Implement class `ScalarConverter` with one static method:
- `static void convert(const std::string& literal);`

Requirements:
- Class is utility-only (must not be instantiable).
- Detect the input literal type, convert to actual value, then explicitly convert and print:
- `char`
- `int`
- `float`
- `double`
- Handle pseudo-literals:
- Float: `nanf`, `+inff`, `-inff`
- Double: `nan`, `+inf`, `-inf`
- If conversion is impossible or overflows, print an informative message.
- If char is non-displayable, print `Non displayable`.

Expected output style (subject examples):
- `char: ...`
- `int: ...`
- `float: ...`
- `double: ...`

Build/run:
```bash
cd ex00
make
./convert 42.0f
```

## ex01 - Serialization
Turn-in files:
- `Makefile`
- `*.cpp`
- `*.hpp` / `*.h`

Goal:
- Implement utility class `Serializer` (non-instantiable) with:
- `static uintptr_t serialize(Data* ptr);`
- `static Data* deserialize(uintptr_t raw);`

Requirements:
- Create a non-empty `Data` structure.
- Serialize pointer -> integer, then deserialize integer -> pointer.
- Demonstrate that deserialized pointer equals original pointer.

Build/run:
```bash
cd ex01
make
./serialize
```

## ex02 - Identify Real Type
Turn-in files:
- `Makefile`
- `*.cpp`
- `*.hpp` / `*.h`

Forbidden:
- `#include <typeinfo>`

Goal:
- Implement polymorphic base class `Base` (public virtual destructor only).
- Create empty derived classes `A`, `B`, `C`.
- Implement:
- `Base* generate(void);` (randomly returns `new A`, `new B`, or `new C`)
- `void identify(Base* p);`
- `void identify(Base& p);`

Requirements:
- `identify(Base*)` prints actual type: `A`, `B`, or `C`.
- `identify(Base&)` prints actual type without using a pointer inside that function.

Build/run:
```bash
cd ex02
make
./identify
```

## Evaluation Checklist
- Correct file names and folder names.
- Compiles cleanly with required flags.
- No leaks from dynamic allocation.
- Correct and explicit cast usage in each exercise.
- Edge cases handled (pseudo-literals, impossible conversions, RTTI behavior).

## Quick Commands
From `CPP06/`:
```bash
make -C ex00
make -C ex01
make -C ex02
```

Clean:
```bash
make -C ex00 fclean
make -C ex01 fclean
make -C ex02 fclean
```
