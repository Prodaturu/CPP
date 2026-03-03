/*
Concept Notes (ex02 - PresidentialPardonForm.hpp)
- Concrete specialization with strictest grades among provided forms (25 sign, 5 execute).
- Target-focused derived class that keeps execution behavior separate from shared checks.
*/
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

/**
 * PresidentialPardonForm
 * Required grades:
 * - sign: 25
 * - execute: 5
 *
 * On execute:
 * - prints pardon message for target
 */
class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		const std::string& getTarget() const;
		virtual void execute(Bureaucrat const& executor) const;
};

#endif
