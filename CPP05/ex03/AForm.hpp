/*
Concept Notes (ex02 - AForm.hpp)
- Abstract base class design with pure virtual execute().
- Shared policy in base class: signed state + sign/execute grade thresholds.
- Protected helper (validateExecution) lets derived classes reuse gatekeeping logic.
- Custom exception hierarchy adds "not signed" execution failure case.
*/
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
		AForm();
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

		/**
		 * Pure virtual function syntax:
		 * `virtual void execute(...) const = 0;`
		 *
		 * Breakdown:
		 * - `virtual` means calls can be resolved at runtime through base references/pointers.
		 * - `= 0` makes this a pure virtual function (no base implementation here).
		 * - Any class containing at least one pure virtual function becomes an abstract class.
		 * - Abstract classes cannot be instantiated directly:
		 *     AForm f(...);  // not allowed
		 * - Derived classes must implement this exact function signature to become concrete.
		 *
		 * Why here:
		 * In ex02, AForm represents a generic interface/contract for all concrete forms.
		 * Each form has different action logic, so execute() is forced in derived classes.
		 */
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
