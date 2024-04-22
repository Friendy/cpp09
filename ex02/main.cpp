/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:51:40 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/22 12:09:07 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"
# include <ctime>



int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cerr << "Error\n";
		return(-1);
	}
	PmergeMe pm(argv[1]);
	pm.sort();
	return (0);
}


