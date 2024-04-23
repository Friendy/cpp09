/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:42:04 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 02:59:08 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void checkLeaks() {
	system("leaks btc");
}

/* 
1. Parsing db
loading db into map container
2. Reading input file entry by entry
take entry from file
taking the key
searching the key in the database
if not found how to find the closest 
(don't forget sorting and limits)
3. output
calculating
formating

 */

// extracts date and value from an input entry

int main(int argc, char *argv[])
{
	// atexit(checkLeaks);
	if (argc <= 1)
	{
		std::cerr << "Error: coudn't open file.\n";
		return(-1);
	}
	BitcoinExchange be("data.csv");
	be.process_file(argv[1]);
	return (0);
}


