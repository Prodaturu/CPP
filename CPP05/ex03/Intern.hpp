#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>

class AForm;

/*
Intern is a simple factory:
- It creates concrete form objects based on a string form name.
- Returned form is heap-allocated; caller owns and must delete it.
*/
class Intern
{
	public:
		// Orthodox Canonical Form
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		// Factory method:
		// - formName selects which form class to instantiate
		// - target is passed to that form constructor
		// - returns NULL if formName is unknown
		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
