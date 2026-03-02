#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade; 						// 1 (highest) to 150 (lowest)

	public:
		// Constructors & Destructor
		Bureaucrat();										// Default Constructor (1)
		Bureaucrat(const std::string& name, int grade); 	// Parameterized Constructor
		Bureaucrat(const Bureaucrat& class_to_be_copied);	// Copy Constructor (2)
		~Bureaucrat();										// Destructor (4)

		// Assignment operator
		Bureaucrat &operator = (const Bureaucrat& class_to_assign_into);

		// Getters
		const std::string& getName() const;
		int getGrade() const;

		// Grade modification methods
		void incrementGrade();
		void decrementGrade();

		// Exception classes
		// The GradeTooHighException is called
		// which overrides the what() method from std::exception to provide a custom error message
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
 * 
 * OCF: Orthodox Canonical Form
 * 
 * A class follows the OCF if it defines the following special member functions:
 * 1) default constructor,
 * 2) copy constructor,
 * 3) assignment operator,
 * 4) destructor,
 * 5) parameterized constructor
 * 
 */

/**
 * 
 * Concept of : Object Assignment and Copying
 * 
 * In C++ we can use copy constructors & assignment operators to define how objects are copied & assigned
 * 
 * This is important for classes that manage resources (like dynamic memory) to avoid issues like double deletion
 * 
 * Here, the Bureaucrat class has a copy constructor and an assignment operator to ensure proper copying of its members
 * 
 * The name is constant and cannot be changed after construction, so it is only set in the constructor
 * 
 * The grade can be modified using incrementGrade & decrementGrade methods, which enforces grade limits.
 * 
 * Exception handling is implemented using custom exceptions derived from std::exception
 * 
 * This allows us to throw meaningful errors when grade constraints are violated
 * 
 * Overall, this class demonstrates proper resource management, encapsulation in C++.
 * 
 */

 
