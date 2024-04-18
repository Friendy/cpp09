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

class NumberTooLarge : public std::exception
{
	virtual const char *what() const throw()
	{
		return("Error: too large a number.");
	}
};

class NegativeNumber : public std::exception
{
	virtual const char *what() const throw()
	{
		return("Error: not a positive number.");
	}
};


// bool check_value(float val)
// {
//	 if (val >= 0 && val <= 1000)
//		 return (true);
//	 return(false);
// }

void process_entry(std::string entry, std::string &date, float &value, BitcoinExchange be)
{
	std::string tmp;
	std::size_t delim = entry.find('|');
	if (delim == std::string::npos)
		std::cout << "Error: bad input => " << entry << std::endl;
	else	
	{
		if (delim > 0)
			date = entry.substr(0, delim - 1); // check if delim isnt 0;
		if (delim <= entry.size() - 1)
			tmp = entry.substr(delim + 2);//
		value = BitcoinExchange::strtof(tmp);
		// std::cout << "val " << tmp << ": " << value << std::endl;
	}
}

void print_output(std::string date, float value, float rate)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << date <<" => " << value << " = " << rate * value << std::endl;
}

int main(int argc, char *argv[])
{
	const char *path = "data.csv";
	BitcoinExchange be;
	std::ifstream input_file;
	std::string entry;
	std::string date = "";
	std::string date1 = "2010-10-22";
	be.checkDate(date1);
	// std::string date2 = "2010-09-26";
	// std::cout << std::min(date1, date2) << std::endl;
	// float value = 0;
	// float rate;
	// be.loadDB(path);
	// std::stringstream ss;
	// // float tmp;
	// // ss << "12";
	// // ss >> tmp;
	// // std::cout << "fl test"<< tmp << std::endl;

	
	// // be.showEntries(300);
	// input_file.open(argv[1]);
	// //check if the path is correct
	// std::getline(input_file, entry);//table header
	// while (!input_file.eof())
	// {
	// 	std::getline(input_file, entry);
	// 	process_entry(entry, date, value, be);
	// 	rate = be.getRate(date);
	// 	print_output(date, value, rate);
	// 	//check entry
	// 	//get output
	

	// 	// std::cout << date << " "<< string_val << std::endl;
	// }
	
	return (0);

}


