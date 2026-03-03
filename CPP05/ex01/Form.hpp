/*
Concept Notes (ex01 - Form.hpp)
- New domain object: Form with private immutable policy fields.
- Encapsulation of permissions: sign grade and execute grade are owned by Form.
- Interface contract: beSigned() validates caller rank and may throw.
- Symmetric exception model with Bureaucrat (too high / too low grades).
*/
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iosfwd>

#include "Bureaucrat.hpp"

/**
 * Form class (ex01):
 * - Immutable name
 * - Signed status flag
 * - Immutable grades required to sign and execute
 * - All fields private (as requested by subject)
 */
class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		// Orthodox Canonical Form
		Form();
		Form(const std::string& name, int signGrade, int executeGrade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		// Accessors required by subject
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		// Try to sign form using bureaucrat grade.
		// Throws GradeTooLowException if bureaucrat rank is insufficient.
		void				beSigned(const Bureaucrat& bureaucrat);

		// Exceptions for invalid form grades.
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Stream output helper to print all useful form information.
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
