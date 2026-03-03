# Exercise 01: Moar brainz!

**Exercise:** 01  
**Title:** Moar brainz!  
**Turn-in directory:** `ex01/`  
**Files to turn in:**  
- `Makefile`  
- `main.cpp`  
- `Zombie.h` or `Zombie.hpp`  
- `Zombie.cpp`  
- `zombieHorde.cpp`  

**Forbidden functions:** None

---

## Task

Create a horde of Zombies!

Implement the following function in the appropriate file:

```cpp
Zombie* zombieHorde(int N, std::string name);
```

- Allocate `N` Zombie objects in a single allocation.
- Initialize each zombie with the given `name`.
- Return a pointer to the first zombie.

---

## Requirements
- Each Zombie should announce itself upon creation.
- Use `new[]` to allocate the array of Zombies.
- Use `delete[]` to free the allocated memory.
- Ensure proper memory management to avoid leaks.
- Follow C++11 standards.