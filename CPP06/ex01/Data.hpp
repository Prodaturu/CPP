#ifndef DATA_HPP
#define DATA_HPP

#include <string>

// Non-empty payload required by the subject so pointer identity is meaningful.
struct Data
{
	int id;
	std::string label;
	double score;
};

#endif
