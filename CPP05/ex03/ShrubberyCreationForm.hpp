/*
Concept Notes (ex02 - ShrubberyCreationForm.hpp)
- Concrete inheritance from AForm with fixed policy grades (145 sign, 137 execute).
- Adds target-specific state used by this form's action.
- Introduces file-related custom exception for execution side effects.
*/
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

/**
 * ShrubberyCreationForm
 * Required grades:
 * - sign: 145
 * - execute: 137
 *
 * On execute: creates <target>_shrubbery and writes ASCII trees into it.
 */
class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		const std::string& getTarget() const;
		virtual void execute(Bureaucrat const& executor) const;

		class FileOpenException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
