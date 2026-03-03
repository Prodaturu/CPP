# CPP01 Ex00 - BraiiiiiiinnnzzzZ

## Overview
Create a zombie class that demonstrates basic C++ concepts: class declaration, constructor/destructor behavior, and proper memory management patterns.

## Requirements
- **Language**: C++98
- **Compiler**: c++ with flags `-Wall -Wextra -Werror -std=c++98`
- **Files**: `Zombie.hpp`, `Zombie.cpp`, `main.cpp`, `newZombie.cpp`, `randomChump.cpp`, `Makefile`
- **Executable**: `zombie`

## Class Design

### Zombie Class
```cpp
class Zombie {
private:
    std::string name;
public:
    Zombie();                           // Default constructor
    Zombie(std::string name);           // Parameterized constructor
    ~Zombie();                          // Destructor
    void announce(void);                // Announce zombie
    void setName(std::string name);     // Set zombie name
};
```

## Core Logic

### 1. Zombie::announce()
- Print: `<name>: BraiiiiiiinnnzzzZ...`
- This method announces the zombie's presence

### 2. Constructor/Destructor Pattern
- **Constructor**: Print creation message with zombie name
- **Destructor**: Print destruction message with zombie name
- This helps track object lifecycle

### 3. Memory Management Functions

#### newZombie(std::string name)
- Allocates zombie on **heap** using `new`
- Returns pointer to zombie
- **Caller responsible for deletion**
- Use case: when zombie needs to survive beyond current scope

#### randomChump(std::string name)
- Creates zombie on **stack** (local variable)
- Calls `announce()` immediately
- **Automatically destroyed** when function ends
- Use case: temporary zombie that doesn't need to persist

## Implementation Strategy

### Step 1: Class Declaration (`Zombie.hpp`)
- Define class with private name member
- Declare all required methods
- Include proper header guards

### Step 2: Class Implementation (`Zombie.cpp`)
- Implement constructors (default + parameterized)
- Implement destructor with debug output
- Implement announce() method
- Implement setName() if using default constructor

### Step 3: Factory Functions
- `newZombie()`: heap allocation, return pointer
- `randomChump()`: stack allocation, immediate announce

### Step 4: Main Function (`main.cpp`)
- Test both allocation patterns
- Demonstrate proper cleanup
- Show constructor/destructor order

## Expected Output Pattern
```
<name>: BraiiiiiiinnnzzzZ...
<name> is being destroyed
```

## Key Learning Points
1. **Stack vs Heap allocation**
2. **Constructor/Destructor lifecycle**
3. **Pointer management and cleanup**
4. **C++98 compliance**
5. **Proper class encapsulation**

## Build & Test
```bash
make all      # Compile
./zombie      # Run
make clean    # Clean objects
make fclean   # Clean all
make re       # Rebuild
```