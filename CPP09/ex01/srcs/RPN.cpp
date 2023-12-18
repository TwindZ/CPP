#include "../inc/RPN.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

RPN::RPN():_stack(), _number1(0), _number2(0)
{
	cout << "RPN constructor call" << endl;
}

RPN::RPN(RPN const& copy)
{
	cout << "RPN copy constructor call" << endl;
	*this = copy;
}

RPN & RPN::operator=(RPN const& copy)
{
	cout << "RPN assignement call" << endl;
	if(this != &copy)
		return *this;
	_stack = copy._stack;
	_number1 = copy._number1;
	_number2 = copy._number2;
	return *this;
}

RPN::~RPN()
{
	cout << "RPN destructor call" << endl;
}

void RPN::execute(string const& arg)
{
	try
	{
		calculate(arg);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void RPN::pushToken(string const& token)
{
	if(token.size() == 1)
		_stack.push(std::stoi(token));
	else
		invalidNumberException();
}

void RPN::popNumbers()
{
	if(_stack.size() < 2)
		missingNumberException();
	_number2 = _stack.top();
	_stack.pop();
	_number1 = _stack.top();
	_stack.pop();
}

int RPN::findOperator(string const& token)const
{
	if(token == "+")
		return SUM;
	else if(token == "-")
		return DIFFERENCE;
	else if(token == "*")
		return PRODUCT;
	else if(token == "/")
		return QUOTIENT;
	else
		return UNKNOWN_OPERATOR;
}

void RPN::printTrace(string const& operation)const
{
	cout << _number1 << " " << operation << " " << _number2 << endl;
}

void RPN::selectOperation(int operation)
{
	switch (operation)
	{
	case SUM:
		_stack.push(_number1 + _number2);
		printTrace("+");
		break;
	case DIFFERENCE:
		_stack.push(_number1 - _number2);
		printTrace("-");
		break;
	case PRODUCT:
		_stack.push(_number1 * _number2);
		printTrace("*");
		break;
	case QUOTIENT:
		if(_number2 != 0)
			_stack.push(_number1 / _number2);
		else
			divisionByZeroException();
		printTrace("/");
		break;
	case UNKNOWN_OPERATOR:
		invalidOperatorException();
	}
}

void RPN::calculate(string const& arg)
{
	string token;
	std::stringstream ss(arg);
	while(ss >> token)
	{
		if(std::isdigit(token[0]))
			pushToken(token);
		else
		{
			popNumbers();
			selectOperation(findOperator(token));
		}
	}
	if(_stack.size() != 1)
		missingOperatorException();
	cout << "Total : " << _stack.top() << endl;
}

std::exception RPN::missingOperatorException()const
{
	throw std::invalid_argument("Error : Missing operator to complete.");
}

std::exception RPN::missingNumberException()const
{
	throw std::invalid_argument("Error : Missing number to complete.");
}

std::exception RPN::invalidOperatorException()const
{
	throw std::invalid_argument("Error : Unknown operator type present");
}

std::exception RPN::invalidNumberException()const
{
	throw std::invalid_argument("Error : Number must be between 0 and 9");
}

std::exception RPN::divisionByZeroException()const
{
	throw std::invalid_argument("Error : Division by zero is not allowed.");
}

