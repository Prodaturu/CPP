# Simple Makefile for CPP00/ex00

#------------------------------------------------------------------------------
# Makefile Documentation
#
# This Makefile is designed for building a simple C++ project (CPP00/ex00).
#
# Targets:
#   all      : Builds the project executable 'megaphone' from source files.
#   $(NAME)  : Links object files to create the final executable.
#   %.o      : Compiles each .cpp source file into a corresponding .o object file.
#   clean    : Removes all object files (.o) from the directory.
#   fclean   : Removes object files and the executable.
#   re       : Rebuilds the project by running 'fclean' followed by 'all'.
#
# Variables:
#   NAME     : Name of the final executable (megaphone).
#   SRCS     : List of source files (.cpp).
#   OBJS     : List of object files (.o) generated from SRCS.
#   CXX      : C++ compiler (c++).
#   CXXFLAGS : Compiler flags for warnings and C++98 standard.
#
# Notes:
#   - Pattern rules are used for compiling source files to object files.
#   - .PHONY is used to declare targets that do not represent files.
#------------------------------------------------------------------------------

NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re