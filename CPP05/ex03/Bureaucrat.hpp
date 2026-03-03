/*
Concept Notes (ex02 - Bureaucrat.hpp)
- Abstraction upgrade: Bureaucrat now works with AForm (abstract base), not concrete Form.
- New behavior executeForm() adds execution orchestration responsibility.
- Polymorphic collaboration allows Bureaucrat to work with multiple form types uniformly.
*/
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iosfwd>

// Forward declaration prevents circular include between Bureaucrat and AForm.
class AForm;

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
		Bureaucrat();
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

		// Bureaucrat attempts to sign a form and prints result message.
		void				signForm(AForm& form) const;

		// ex02 requirement:
		// Bureaucrat attempts to execute a form and prints result message.
		void				executeForm(AForm const& form) const;

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
