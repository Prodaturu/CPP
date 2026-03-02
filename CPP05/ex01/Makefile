# Final executable name requested by exercise directory naming convention.
NAME = ex01

# Source files for exercise 01:
# - Bureaucrat class from ex00 + signForm() addition
# - New Form class
# - Test driver
SRCS = Bureaucrat.cpp Form.cpp main.cpp

# Object files auto-derived from SRCS.
OBJS = $(SRCS:.cpp=.o)

# Compiler and flags:
# - Strict warnings
# - C++11 (your campus rule)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Default build target.
all: $(NAME)

# Link all object files into one executable.
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Generic compile rule:
# each .cpp becomes one .o file.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove intermediate object files.
clean:
	rm -f $(OBJS)

# Remove objects + executable.
fclean: clean
	rm -f $(NAME)

# Full rebuild from scratch.
re: fclean all

.PHONY: all clean fclean re
