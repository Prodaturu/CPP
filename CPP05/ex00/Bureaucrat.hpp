#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
	private:
		/* data */
		const std::string	_name;
		int 				_grade;


	public:

	/*--- --- --- Constructors and Destructors --- --- ---*/

		// default ctor and dtor
		Bureaucrat();										// default constructor / ctor
		~Bureaucrat();										// destructor / dtor

		// parameterized constructor
		Bureaucrat(const std::string& name, int grade);
		
		// copy constructor
		Bureaucrat(const Bureaucrat& other);

	/*--- --- --- Member Functions --- --- ---*/
	
		// Getters
		const std::string	getName();
		int					getGrade();

		// Grade modification
		void				incrementGrade();
		void				decrementGrade();

		// Operator overload
		Bureaucrat&			operator=(const Bureaucrat& other);

	/**--- --- --- Error Handling --- --- ---*/

		class				GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too high!";
				}
		};

		class				GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too low!";
				}
		};

		// End of class Bureaucrat
};

// Overload the insertion operator for easy printing of Bureaucrat details
// Non-member function to allow access to private members via friend declaration if needed
// This function enables usage like: std::cout << bureaucrat;
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP

/** Reason why insertion operator is a non member function
 * 
 * The insertion operator (<<) is often implemented as a non-member function to allow for
 * flexibility and consistency in how objects are printed to output streams.
 * 
 * 1. Symmetry with Built-in Types:
 * The insertion operator is already defined for built-in types (like int, double, etc.)
 * By defining it as a non-member for user-defined types,
 * it maintains symmetry and consistency in how the operator is used across different types
 * 
 * 2. Access to Private Members:
 * By declaring the operator as a friend of the class,
 * it can access private and protected members of the class directly
 * This is useful for printing internal state without needing public getters
 * 
 * 3. Separation of Concerns:
 * Keeping operator outside the class definition separates data representation and data manipulation
 * The class focuses on its core functionality,
 * while the operator handles how the object is represented in output streams
 * 
 * 4. Flexibility in Overloading:
 * Non-member functions can be more flexible in terms of overloading
 * They can be defined to work with different types of streams or different combinations of types,
 * allowing for more versatile usage
 * 
 * 5. Consistency with Other Operators:
 * Many other operators (like arithmetic operators) are also implemented as non-member functions
 * This maintains a consistent approach to operator overloading in C++.
 * 
 * In summary
 * implementing the insertion operator as a non-member function provides greater flexibility,
 * maintains consistency with built-in types
 * allows for better separation of concerns in class design.
 * 
 * Usability with Standard Streams:
 * If the insertion operator were implemented as a member function,
 * it would require the left-hand operand to be an instance of the class.
 * This would limit its usability, as the left-hand side is typically an output stream (like std::cout),
 * which is not a member of the class. By making it a non-member function,
 * we allow the operator to work seamlessly with standard output streams.
 * 
 */
