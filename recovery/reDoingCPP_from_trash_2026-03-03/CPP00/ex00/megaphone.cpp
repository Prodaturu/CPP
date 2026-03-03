#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	// Only one argument allowed - do argument check
	if (argc != 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	// loop through each string
	for (int i = 1; i < argc; ++i)
	{
		// loop through each character in a string
		for (int j = 0; argv[i][j]; ++j)
		{
			// toupper() returns an int
			// so the output from toupper is casted to char
			// before giving it as an input to std::cout
			std::cout << static_cast<char>( std::toupper(argv[i][j]) );
		}
		// print a space between separate argv entries so words don't concatenate
		if (i < argc - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}
