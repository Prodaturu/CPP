#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iosfwd>

// Forward declaration prevents circular include between Bureaucrat and Form.
class Form;

/**
 * Bureaucrat class:
 * - Name is immutable after construction.
 * - Grade is always in [1, 150].
 *   1 = highest rank, 150 = lowest rank.
 */
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		// Orthodox Canonical Form
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		// Accessors
		const std::string&	getName() const;
		int					getGrade() const;

		// Grade operations
		void				incrementGrade();
		void				decrementGrade();

		// ex01 requirement:
		// Bureaucrat attempts to sign a form and prints result message.
		void				signForm(Form& form) const;

		// Nested exception types for invalid grade manipulations.
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

// Print format required by subject:
// "<name>, bureaucrat grade <grade>."
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
