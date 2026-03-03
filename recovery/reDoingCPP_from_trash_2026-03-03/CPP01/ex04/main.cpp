// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.
// It must open the file <filename> and copy its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.
// Using C file manipulation functions is forbidden and will be considered cheating. All
// the member functions of the class std::string are allowed, except replace. Use them
// wisely!
// Of course, handle unexpected inputs and errors. You must create and turn in your
// own tests to ensure that your program works as expected.
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	// Check for correct number of arguments
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	// Extract arguments
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Open input file
	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}

	// Create output file
	std::string outFilename = filename + ".replace";
	std::ofstream outputFile(outFilename);
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file " << outFilename << std::endl;
		return 1;
	}

	// Read input file line by line
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		// Replace all occurrences of s1 with s2 in the line
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length(); // Move past the replaced string
		}
		// Write modified line to output file
		outputFile << line << std::endl;
	}
	return 0;
}