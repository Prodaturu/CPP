#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const char*			_name;		//const name attribute
	int					_grade;

public:
	/* --- --- --- Constructors and Destructors */

	// Default Ctor & dtor
	Bureaucrat();
	~Bureaucrat();

	// Parameterised Ctor
	Bureaucrat(const char* name, int grade);
	
};

#endif
