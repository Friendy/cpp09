/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:51:40 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/22 22:35:36 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"
# include <ctime>

void checkLeaks() {
	system("leaks PmergeMe");
}


int main(int argc, char *argv[])
{
	atexit(checkLeaks);
	if (argc <= 1)
	{
		std::cerr << "Error\n";
		return(-1);
	}
	PmergeMe pm(argc, argv);
	pm.sort();
	return (0);
}


