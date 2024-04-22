/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:16:49 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 01:51:25 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*CONSTRUCTORS*/
RPN::RPN(){}

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

bool RPN::isoperator(int n)
{
	return(n == '+' || n == '-' || n == '*'|| n == '/');
}

bool RPN::is_digit(int n)
{
	return(n >= '0' && n <= '9');
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

int RPN::err()
{
	std::cerr << "Error\n";
	exit(0);
}

int RPN::runStack(std::string arg)
{
	int operand1;
	int	operand2;

	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it)
	{
		if (*it != ' ')
		{
			if (!is_digit(*it) && !isoperator(*it))
				err();
			if (is_digit(*it))
				_stack.push(*it - '0');
			else if (!_stack.empty())
			{
				operand2 = _stack.top();
				_stack.pop();
				if (!_stack.empty())
				{
					operand1 = _stack.top();
					_stack.pop();
					operand1 = this->operation(operand1, operand2, *it);
					if (it != arg.end() - 1)
						_stack.push(operand1);
				}
				else
					err();
			}
		}
	}
	if (!_stack.empty())
		err();
	return(operand1);
}

/*DESTRUCTOR*/
RPN::~RPN(){}
