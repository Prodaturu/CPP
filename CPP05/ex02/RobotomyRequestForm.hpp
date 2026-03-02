#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

/**
 * RobotomyRequestForm
 * Required grades:
 * - sign: 72
 * - execute: 45
 *
 * On execute:
 * - makes drilling noises
 * - 50% success chance
 */
class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		const std::string& getTarget() const;
		virtual void execute(Bureaucrat const& executor) const;
};

#endif
