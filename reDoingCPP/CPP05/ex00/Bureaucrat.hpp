#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade; // 1 (highest) to 150 (lowest)

	public:
		// Constructors & Destructor
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		// Assignment operator
		Bureaucrat& operator=(const Bureaucrat& other);

		// Getters
		const std::string& getName() const;
		int getGrade() const;

		// Grade modification methods
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

#endif // BUREAUCRAT_HPP

/**
 * Concept of : Object Assignment and Copying
 * 
 * In C++ we can use copy constructors & assignment operators to define how objects are copied & assigned
 * This is important for classes that manage resources (like dynamic memory) to avoid issues like double deletion
 * Here, the Bureaucrat class has a copy constructor and an assignment operator to ensure proper copying of its members
 * The name is constant and cannot be changed after construction, so it is only set in the constructor
 * The grade can be modified using incrementGrade & decrementGrade methods, which enforces grade limits.
 * Exception handling is implemented using custom exceptions derived from std::exception
 * This allows us to throw meaningful errors when grade constraints are violated
 * Overall, this class demonstrates proper resource management, encapsulation in C++.
 */
