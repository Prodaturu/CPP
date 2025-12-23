#include "Bureaucrat.hpp"

/** @brief Initializer List
 * the syntax `ClassName::ClassName(parameters) : a(parameters)), b(parameter) ...`
 * 		is used to initialize member variables
 * This is called an "initializer list".
 * 
 * It is more efficient than assigning values inside the constructor body,
 * 		because it directly initializes the members
 * 		rather than default-constructing and then assigning.
 * 
 * For const members (like _name), they must be initialized in the initializer list
 * 		because they cannot be assigned to after construction.
 * 
 * Also, for members that are classes with no default constructor,
 * 		they must be initialized in the initializer list.
 * 
*/

/* --- --- --- Constructors & Destructor --- --- --- */

// parameterized constructor //
// initializes _name and _grade using initializer list
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	// the above line directly initializes _name and _grade
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// default constructor //
// initializes _name to "fillerName" and _grade to 150
Bureaucrat::Bureaucrat() : _name("fillerName"), _grade(150)
{
	// default constructor body can be empty since members are initialized above
}

// destructor //
// no special cleanup needed in this case as no dynamic memory is used
Bureaucrat::~Bureaucrat()
{
	// destructor body can be empty if no special cleanup is needed
}

/* --- --- --- Getters --- --- --- */

// return the name of the Bureaucrat
const	std::string Bureaucrat::getName()
{
	return this->_name;
}

// return the grade of the Bureaucrat
int Bureaucrat::getGrade()
{
	return this->_grade;
}

/* --- --- --- Grade Modification --- --- --- */

// increment the grade (decrease the numerical value)
void Bureaucrat::incrementGrade()
{
	if (this -> _grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this -> _grade--;
}

// decrement the grade (increase the numerical value)
void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

// Overload the insertion operator for easy printing of Bureaucrat details
