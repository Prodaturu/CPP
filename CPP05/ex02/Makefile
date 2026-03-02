# Concept Notes (ex02 - Makefile)
# - Build graph now includes abstract base + multiple concrete derived classes.
# - Single executable links all polymorphic form implementations.
# - Standard target lifecycle stays consistent across exercises.

# Final executable name follows exercise directory name.
NAME = ex02

# Source files for ex02:
# - Bureaucrat from previous exercises, now with executeForm()
# - Abstract base class AForm
# - Three concrete forms
# - main test file
SRCS = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp

# Automatically convert .cpp list into .o list.
OBJS = $(SRCS:.cpp=.o)

# Compiler setup:
# - strict warnings enabled
# - C++11 standard as requested in your campus setup
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Default target: build the whole executable.
all: $(NAME)

# Link object files into final program.
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Generic compilation rule for each translation unit.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove only generated object files.
clean:
	rm -f $(OBJS)

# Remove objects and final binary.
fclean: clean
	rm -f $(NAME)

# Rebuild from a fully clean state.
re: fclean all

.PHONY: all clean fclean re
