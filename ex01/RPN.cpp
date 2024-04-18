#include "RPN.hpp"

/*CONSTRUCTORS*/
RPN::RPN()
{
}

//Assignment operator:
RPN &RPN::operator=(RPN const &original)
{
	if (this != &original)
		this->_stack = original._stack;
	return(*this);
}

RPN::RPN(RPN const &original)
{
	*this = original;
}

/*FUNCTIONS*/

static bool isoperator(int n)
{
	return(n == '+' || n == '-' || n == '*'|| n == '/');
}


int RPN::operation(int operand1, int operand2, int token)
{
	switch(token)
	{
		case ('+') :
			return( operand1 + operand2);
		case ('-') :
			return( operand1 - operand2);
		case ('*') :
			return( operand1 * operand2);
		case ('/') :
			return( operand1 / operand2);
	}
	return(0);
}

int RPN::runStack(std::string arg)
{
	int operand1;
	int	operand2;

	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it)
	{
		if (*it != ' ')
		{
			if (!isoperator(*it))
				_stack.push(*it - '0');
			else
			{
				operand2 = _stack.top();
				_stack.pop();
				operand1 = _stack.top();
				_stack.pop();
				operand1 = this->operation(operand1, operand2, *it);
				if (it != arg.end())
					_stack.push(operand1);
			}
		}
	}
	return(operand1);
}

/*DESTRUCTOR*/
RPN::~RPN(){}
