/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:14:19 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 02:51:06 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <iomanip>
# include <stdexcept>

typedef unsigned int u_int;
typedef std::map<std::string, float>::iterator Iterator;

class BitcoinExchange {

private:
	std::string _entry;
	std::map<std::string, float> _db;
	std::string _ref_date;
	std::ifstream _input_file;
	std::string _date;
	float _value;
	float _rate;

public:
	//main functions
	void process_file(const char *input_path);
	void process_entry();
	void checkDate(const std::string date);
	float getRate();
	void print_output();

	//helper functions
	static float strtof(std::string str);
	static int strtoi(std::string str);
	int getPrecision(float f);
	void showEntries(u_int n);

	//exceptions
	class BadDate;
	class DateOutOfBounds;
	class NumberTooLarge;
	class NegativeNumber;
	class BadInput;

	BitcoinExchange();
	BitcoinExchange(const char *path);
	BitcoinExchange(BitcoinExchange const &original);
	BitcoinExchange &operator=(BitcoinExchange const &original);
	~BitcoinExchange();
};

#endif
