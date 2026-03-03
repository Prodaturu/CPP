NAME = brain

SRCS = main.cpp

# Replace .cpp with .o for each source file (no space between ':' and pattern)
OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "Executable $(NAME) created!"
	@echo "Use ./$(NAME) to run the program."

# Compile each .cpp file to .o $< i.e; first prerequisite (.cpp file's), $@ means the target (.o file's)
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
	@echo "Compiled $< to $@"

clean:
	@rm -f $(OBJS)
	@echo "Cleaned up object files."
	@echo "Use 'make fclean' to remove the executable as well."

fclean: clean
	@rm -f $(NAME)
	@echo "Removed executable $(NAME)."
	@echo "Use 'make all' to rebuild the executable."

re: fclean all
	@echo "Rebuilt everything from scratch."
	@echo "Use ./$(NAME) to run the program."

# For debugging
debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
# .PHONY indicates that these are not files, but just commands