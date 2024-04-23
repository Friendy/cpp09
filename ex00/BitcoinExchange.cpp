/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:14:16 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 13:16:09 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*EXCEPTIONS*/
class BitcoinExchange::BadInput : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return("Error: bad input => ");
		}
};

class BitcoinExchange::BadDate : public BitcoinExchange::BadInput
{
	public:
		virtual const char *what() const throw()
		{
			return("Error: date is incorrect. => ");
		}
};

class BitcoinExchange::DateOutOfBounds : public BitcoinExchange::BadInput
{
	public:
	virtual const char *what() const throw()
	{
		return("Error: date out of scope. => ");
	}
};

class BitcoinExchange::NumberTooLarge : public std::exception
{
	public:
	virtual const char *what() const throw()
	{
		return("Error: too large a number.");
	}
};

class BitcoinExchange::NegativeNumber : public std::exception
{
	public:
	virtual const char *what() const throw()
	{
		return("Error: not a positive number.");
	}
};

/*CONSTRUCTORS*/
BitcoinExchange::BitcoinExchange(){}

/*
first getline is to omit the header
 */
BitcoinExchange::BitcoinExchange(const char *path)
{
	std::ifstream db_file;
	std::string date;
	std::string string_val;

	db_file.open(path);
	if (db_file.fail())
	{
		std::cerr << "Error: bad database path.\n";
		exit(0);
	}
	std::getline(db_file, date);
	while (!db_file.eof())
	{
		std::getline(db_file, date, ',');
		std::getline(db_file, string_val);
		if (date.size() > 0)
			_db[date] = this->strtof(string_val);
	}
}

//Assignment operator:
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &original)
{
	if (this != &original)
	{
		_entry = original._entry;
		_db = original._db;
		_ref_date = original._ref_date;
		_date = original._date;
		_value = original._value;
		_rate = original._rate;
	}
	return(*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &original)
{
	*this = original;
}

/*FUNCTIONS*/

//main functions
void BitcoinExchange::process_file(const char *input_path)
{
	_input_file.open(input_path);
	if (_input_file.fail())
	{
		std::cerr << "Error: coudn't open file.\n";
		exit(0);
	}
	std::getline(_input_file, _entry);
	while (!_input_file.eof())
	{
		std::getline(_input_file, _entry);
		try
		{
			process_entry();
			checkDate(_date);
			_rate = getRate();
			print_output();
		}
		catch (BitcoinExchange::BadInput &e)
		{
			std::cerr << e.what() << _entry << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::process_entry()
{
	std::string val_string;
	if (_entry.size() < 14)
		throw BadInput();
	std::size_t delim = _entry.find('|');
	if (delim == std::string::npos || delim != 11 || _entry[12] != ' ')
		throw BadInput();
	_date = _entry.substr(0, delim - 1);
	if (delim < _entry.size() - 1)
		val_string = _entry.substr(delim + 2);
	else
		throw BadInput();
	_value = BitcoinExchange::strtof(val_string);
	if (_value < 0)
		throw NegativeNumber();
	if (_value > 1000)
		throw NumberTooLarge();
}

void BitcoinExchange::checkDate(const std::string date)
{
	if (date[4] != '-' || date[7] != '-')
		throw BadDate();
	if (date < _db.begin()->first || date > _db.rbegin()->first)
			throw DateOutOfBounds();
	int year = BitcoinExchange::strtoi(date.substr(0, 4));
	int month = BitcoinExchange::strtoi(date.substr(5, 2));
	int day = BitcoinExchange::strtoi(date.substr(8, 2));
	checkDateGeo(year, month, day);
}

void BitcoinExchange::checkDateGeo(int year, int month, int day)
{
	bool leap = false;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw BadDate();
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		leap = true;
	if (month == 2 && leap && day > 29)
		throw BadDate();
	else if (month == 2 && !leap && day > 28)
		throw BadDate();
	if ((month == 9 || month == 4 || month == 6 || month == 11) && day > 30)
		throw BadDate();
}

float BitcoinExchange::getRate()
{
	std::map<std::string, float>::iterator it;
	it = _db.find(_date);
	if (it == _db.end())
	{
		it = _db.upper_bound(_date);
		if (it != _db.begin())
			--it;
	}
	return(it->second);
}

int BitcoinExchange::getPrecision(float f)
{
	if (abs(f - static_cast<int>(f)) < 0.0001)
		return(0);
	f = f * 10;
	if (abs(f - static_cast<int>(f)) < 0.0001)
		return(1);
	return(2);
}

void BitcoinExchange::print_output()
{
	int prec_val;
	int prec_price;
	float price;

	price = _rate * _value;
	prec_val = getPrecision(_value);
	prec_price = getPrecision(price);

	std::cout << std::fixed << std::setprecision(prec_val);
	std::cout << _date <<" => " << _value << " = ";
	std::cout << std::fixed << std::setprecision(prec_price);
	std::cout << _rate * _value << std::endl;
}

//helper functions
float BitcoinExchange::strtof(std::string str)
{
	std::stringstream ss;
	float val;

	ss << str;
	ss >> val;
	return (val);
}

int BitcoinExchange::strtoi(std::string str)
{
	std::stringstream ss;
	int val;

	ss << str;
	ss >> val;
	return (val);
}

void BitcoinExchange::showEntries(u_int n)
{
	std::map<std::string, float>::iterator it = _db.begin();
	for (u_int i = 0; i <= n; i++)
	{
		std::cout << it->first <<" "<< std::fixed << std::setprecision(2) << it->second << std::endl;
		++it;
	}
}

/*DESTRUCTOR*/
BitcoinExchange::~BitcoinExchange(){}
