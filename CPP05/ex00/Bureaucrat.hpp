#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
	private:
		/* data */
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(); 										// default constructor
		Bureaucrat(const std::string& name, int grade);		// parameterized constructor
		~Bureaucrat();										// destructor	
};

Bureaucrat::Bureaucrat(/* args */)
{

}

Bureaucrat::~Bureaucrat()
{

}


#endif // BUREAUCRAT_HPP