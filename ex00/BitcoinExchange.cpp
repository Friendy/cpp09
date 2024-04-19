/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:14:16 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/19 19:45:52 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

class BitcoinExchange::DateTooLow : public BitcoinExchange::BadInput
{
	public:
	virtual const char *what() const throw()
	{
		return("Error: date is lower than in any entry. => ");
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
BitcoinExchange::BitcoinExchange()
{
	// std::cout << "class created" << std::endl;
}

//Assignment operator:
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &original)
{
	if (this != &original)
		this->_entry = original._entry;
	return(*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &original)
{
	*this = original;
}

/*FUNCTIONS*/
// const std::string BitcoinExchange::getEntry() const
// {
// 	return(this->_entry);
// }
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
	for (int i = 0; i <= n; i++)
	{
		std::cout << it->first <<" "<< std::fixed << std::setprecision(2) << it->second << std::endl;
		++it;
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
		//std::cout << "Error: bad input => " << entry << std::endl;
	_date = _entry.substr(0, delim - 1); // check if delim isnt 0;
	// std::cout << "dl " << delim << ": " << entry[13] << std::endl;
	if (delim < _entry.size() - 1)
		val_string = _entry.substr(delim + 2);//
	else
		throw BadInput();
	_value = BitcoinExchange::strtof(val_string);
	if (_value < 0)
		throw NegativeNumber();
	if (_value > 1000)
		throw NumberTooLarge();
	// std::cout << "val " << val_string << ": " << value << std::endl;
}

void BitcoinExchange::checkDate(const std::string date)
{
	bool check = true;
	std::string min = (*std::min_element(_db.begin(), _db.end())).first;
	int year = BitcoinExchange::strtoi(date.substr(0, 4));
	int month = BitcoinExchange::strtoi(date.substr(5, 2));
	int day = BitcoinExchange::strtoi(date.substr(8, 2));
	// std::cout << year << std::endl;
	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw BadDate();
	if (date < min)
		throw DateTooLow();
	// check = (date >= min && date <= max) && (month >= 1 && month <= 12);
	check = check && (day >= 1 && day <= 31);//!!!February
	
	// if ()

}

void BitcoinExchange::loadDB(const char *path)
{
	std::ifstream db_file;
	std::string date;
	std::string string_val;

	db_file.open(path);
	std::getline(db_file, date);//table header
	while (!db_file.eof())
	{
		std::getline(db_file, date, ',');
		std::getline(db_file, string_val);
		if (date.size() == 10) //create better date checker
			_db[date] = this->strtof(string_val);
	}
}

void BitcoinExchange::print_output()
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << _date <<" => " << _value << " = " << _rate * _value << std::endl;
}

void BitcoinExchange::process_file(const char *db_path, const char *input_path)
{
	loadDB(db_path);
	_input_file.open(input_path);
	//check if the path is correct!!!
	std::getline(_input_file, _entry);//table header
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

// bool 

// Iterator BitcoinExchange::getClose(std::string date)
// {
// 	Iterator it;
// 	if (!std::is_sorted(_db.begin(), _db.end()))
// 		_db.s
// 	it = _db.upper_bound(date);
// 		std::cout << "sorted?" << std::is_sorted(_db.begin(), _db.end()) << std::endl;
// 	if ()
// 	it = _db.find(date);
// 	if (it != _db.end())
// 		return(it->second);
// 	else
// 		return(this->getClose(date));
// 		// return(100000);
// 	//implement close date
// }

float BitcoinExchange::getRate()
{
	std::map<std::string, float>::iterator it;
	it = _db.find(_date);
	if (it == _db.end())
	{
		it = _db.upper_bound(_date);
		if (it != _db.begin())
			--it;
		// std::cout << "lower?" << it->first << std::endl;
	}
	return(it->second);
	// return(this->getClose(date));
		// return(100000);
	//implement close date
}

/*DESTRUCTOR*/
BitcoinExchange::~BitcoinExchange(){}
