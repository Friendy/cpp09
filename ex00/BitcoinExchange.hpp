/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:14:19 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/19 19:02:40 by mrubina          ###   ########.fr       */
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
	void loadDB(const char *path);
	static float strtof(std::string str);
	static int strtoi(std::string str);
	void checkDate(const std::string date);
	void showEntries(u_int n);
	float getRate();
	void process_file(const char *db_path, const char *input_path);
	void print_output();
	void process_entry();
	
	Iterator getClose(std::string date);

	class BadDate;
	class DateTooLow;
	class NumberTooLarge;
	class NegativeNumber;
	class BadInput;

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &original);
	BitcoinExchange &operator=(BitcoinExchange const &original);
	~BitcoinExchange();
};

#endif
