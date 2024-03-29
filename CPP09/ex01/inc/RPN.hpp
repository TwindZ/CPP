#ifndef RPN_HPP
# define RPN_HPP

# define SUM 0
# define DIFFERENCE 1
# define PRODUCT 2
# define QUOTIENT 3
# define UNKNOWN_OPERATOR 4

# include <iostream>
# include <stack>
# include <string>
# include <exception>
# include <stdexcept>
# include <sstream>

class RPN
{
	public:

		RPN();
		RPN(RPN const& copy);
		RPN & operator=(RPN const& copy);
		~RPN();

		void execute(std::string const& arg);

	private:

		void calculate(std::string const& arg);
		void pushToken(std::string const& token);
		void popNumbers();
		int findOperator(std::string const& token)const;
		void printTrace(std::string const& operation)const;
		void selectOperation(int operation);


		std::exception missingOperatorException()const;
		std::exception missingNumberException()const;
		std::exception invalidOperatorException()const;
		std::exception invalidNumberException()const;
		std::exception divisionByZeroException()const;

		std::stack<int> _stack;
		int	_number1;
		int	_number2;

};

#endif