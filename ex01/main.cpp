/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:16:42 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 01:40:36 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc <= 1 || argv[1][0] == '\0' || argv[1][0] == ' ')
	{
		std::cerr << "Error\n";
		return(-1);
	}
	RPN rpn;
	std::cout << rpn.runStack(argv[1]) << std::endl;
	return (0);
}


