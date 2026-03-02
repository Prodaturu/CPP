#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

namespace
{
	// Small helper creators so we can map names to creation functions.
	AForm* createShrubbery(const std::string& target)
	{
		return new ShrubberyCreationForm(target);
	}

	AForm* createRobotomy(const std::string& target)
	{
		return new RobotomyRequestForm(target);
	}

	AForm* createPardon(const std::string& target)
	{
		return new PresidentialPardonForm(target);
	}
}

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	struct FormEntry
	{
		const char* name;
		AForm* (*creator)(const std::string& target);
	};

	static const FormEntry formTable[] = {
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPardon}
	};

	for (size_t i = 0; i < sizeof(formTable) / sizeof(formTable[0]); ++i)
	{
		if (formName == formTable[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formTable[i].creator(target);
		}
	}

	std::cout << "Intern cannot create \"" << formName << "\"" << std::endl;
	return NULL;
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form requested.";
}
