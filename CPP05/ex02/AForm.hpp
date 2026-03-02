#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iosfwd>

class Bureaucrat;

/**
 * AForm is an abstract base class for executable forms.
 *
 * Shared rules:
 * - Name is immutable.
 * - Sign grade and execute grade are immutable and must stay in [1, 150].
 * - Form must be signed before execution.
 */
class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		// Orthodox Canonical Form for base class.
		AForm(const std::string& name, int signGrade, int executeGrade);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		// Basic accessors.
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		// Try to sign this form with a bureaucrat.
		void				beSigned(const Bureaucrat& bureaucrat);

		// Each concrete form implements its own execution behavior.
		virtual void		execute(Bureaucrat const& executor) const = 0;

	protected:
		// Shared validation logic for derived execute() implementations.
		// Throws if form is unsigned or executor grade is too low.
		void				validateExecution(const Bureaucrat& executor) const;

	public:
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Stream output for debugging/tests.
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
