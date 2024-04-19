/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:42:04 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/19 19:47:18 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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



// class BadDate : public std::exception
// {
// 	public:
// 	virtual const char *what() const throw()
// 	{
// 		return("Error: date is incorrect. =>");
// 	}
// };

// class DateTooLow : public BadDate
// {
// 	public:
// 	virtual const char *what() const throw()
// 	{
// 		return("Error: date is too low. =>");
// 	}
// };


// bool check_value(float val)
// {
// 	if (val >= 0 && val <= 1000)
// 		return (true);
// 	return(false);
// }

// extracts date and value from an input entry
// void process_entry(std::string entry, std::string &date, float &value, BitcoinExchange be)
// {
// 	std::string val_string;
// 	if (entry.size() < 14)
// 		throw BadInput();
// 	std::size_t delim = entry.find('|');
// 	if (delim == std::string::npos || delim != 11 || entry[12] != ' ')
// 		throw BadInput();
// 		//std::cout << "Error: bad input => " << entry << std::endl;
// 	date = entry.substr(0, delim - 1); // check if delim isnt 0;
// 	// std::cout << "dl " << delim << ": " << entry[13] << std::endl;
// 	if (delim < entry.size() - 1)
// 		val_string = entry.substr(delim + 2);//
// 	else
// 		throw BadInput();
// 	value = BitcoinExchange::strtof(val_string);
// 	if (value < 0)
// 		throw NegativeNumber();
// 	if (value > 1000)
// 		throw NumberTooLarge();
// 	// std::cout << "val " << val_string << ": " << value << std::endl;
// }


int main(int argc, char *argv[])
{
	//add larger than upper
	const char *path = "data.csv";
	BitcoinExchange be;
	be.process_file("data.csv", "input.txt");
	// float value = 0;
	// float rate;

	

		// std::cout << date << " "<< string_val << std::endl;
	
	
	return (0);

}


