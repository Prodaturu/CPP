#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

// RPN calculator for expressions in Reverse Polish Notation.
// Example input:
//   "8 9 * 9 - 9 - 9 - 4 - 1 +"
// Each token is separated by spaces.
// Operands are restricted to single-digit positive integers [0..9].
class RPN
{
private:
	// Evaluation stack: push numbers, pop two values for each operator.
	std::stack<long> _stack;

	// Token classifier and operator executor.
	bool isOperator(const std::string &token) const;
	long applyOperation(long left, long right, char op) const;

public:
	// Orthodox Canonical Form.
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	// Evaluate one full RPN expression.
	// Throws std::runtime_error("Error") on invalid input.
	long evaluate(const std::string &expression);
};

#endif
