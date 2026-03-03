#include "RPN.hpp"

#include <cstdlib>
#include <sstream>
#include <stdexcept>

// Default constructor.
RPN::RPN()
{
}

// Copy constructor: stack copy is value-based.
RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

// Assignment operator.
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

// Destructor.
RPN::~RPN()
{
}

// Operator token must be exactly one char among + - * /
bool RPN::isOperator(const std::string &token) const
{
	return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

// Applies binary operation in order: left <op> right.
// Throws on division by zero.
long RPN::applyOperation(long left, long right, char op) const
{
	if (op == '+')
		return left + right;
	if (op == '-')
		return left - right;
	if (op == '*')
		return left * right;
	if (right == 0)
		throw std::runtime_error("Error");
	return left / right;
}

// Full evaluator.
// Algorithm:
// 1) split expression by spaces
// 2) for number token -> push
// 3) for operator token -> pop 2, apply, push result
// 4) at end, exactly one result must remain
long RPN::evaluate(const std::string &expression)
{
	// Ensure object can be reused for multiple evaluations.
	while (!_stack.empty())
		_stack.pop();

	std::istringstream iss(expression);
	std::string token;

	// Read each space-separated token.
	while (iss >> token)
	{
		if (isOperator(token))
		{
			// Need at least two operands before applying an operator.
			if (_stack.size() < 2)
				throw std::runtime_error("Error");

			// Pop order matters for non-commutative ops.
			long right = _stack.top();
			_stack.pop();
			long left = _stack.top();
			_stack.pop();

			// Push computed intermediate result.
			_stack.push(applyOperation(left, right, token[0]));
		}
		else
		{
			// Subject constraints: only single-digit positive numbers are valid tokens.
			if (token.length() != 1 || token[0] < '0' || token[0] > '9')
				throw std::runtime_error("Error");
			_stack.push(std::strtol(token.c_str(), NULL, 10));
		}
	}

	// Final stack must contain exactly one computed result.
	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}
