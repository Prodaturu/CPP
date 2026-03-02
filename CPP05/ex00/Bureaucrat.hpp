#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>	// for std::exception
#include <iosfwd>		// for std::ostream

// #include <stdexcept>	// for std::runtime_error

/**
 * Bureaucrat invariants:
 * - _name is immutable after construction.
 * - _grade is always kept in the inclusive range [1, 150].
 *   1 is the highest rank, 150 is the lowest rank.
 */
class Bureaucrat
{
	private:
		/* data */
		const std::string	_name;
		int 				_grade;


	public:

	/*--- --- --- Constructors and Destructors --- --- ---*/

		// default ctor and dtor -  not defined to prevent 
		// Bureaucrat();										// default constructor / ctor
		
		// parameterized constructor
		Bureaucrat(const std::string& name, int grade);

		/**
		 * Rule of Three:
		 * If a class defines one of the following it should probably explicitly define all three:
		 * 1. Destructor
		 * 2. Copy Constructor
		 * 3. Copy Assignment Operator
		 */

		//1. Destructor
		~Bureaucrat();										// destructor / dtor

		//2. Copy Constructor
		Bureaucrat(const Bureaucrat& other);				// copy constructor - initializes a new object as a copy of an existing object

		//3. Copy Assignment Operator
		Bureaucrat& 		operator=(const Bureaucrat& other);	// copy assignment operator 
		// ('= / assignment perator' overloading) - assigns the values from  existing object to another existing object (after both have been constructed)


	/*--- --- --- Member Functions --- --- ---*/
	
		// Getters
		const std::string	&getName() const;
		int					getGrade() const;

		// Grade modification
		void				incrementGrade();
		void				decrementGrade();

	/**--- --- --- Error Handling --- --- ---*/

		class				GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class				GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// End of class Bureaucrat
};

// Overload the insertion operator for easy printing of Bureaucrat details
// Non-member function to allow access to private members via friend declaration if needed
	// but we can use public getters instead too, so friend declaration is not strictly necessary here
	// Just keep in mind that we can also use friend instead of public getters
	// if we want to access private members directly without exposing them through public methods
	// since its not a concern here, we can use public getters instead of friend.
// This function enables usage like: std::cout << bureaucrat;
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

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
