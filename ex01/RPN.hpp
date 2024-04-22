/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:16:52 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 01:45:19 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <iostream>
# include <stack>

class RPN {

private:
	std::stack<int> _stack;

public:
	int runStack(std::string arg);
	int operation(int operand1, int operand2, int token);
	int err();
	bool is_digit(int n);
	bool isoperator(int n);

	RPN();
	RPN(RPN const &original);
	RPN &operator=(RPN const &original);
	~RPN();
};

#endif
