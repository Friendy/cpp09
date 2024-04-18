#include "BitcoinExchange.hpp"

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

bool BitcoinExchange::checkDate(const std::string date)
{
	bool check = true;
	std::string min = (*std::min_element(_db.begin(), _db.end())).first;
	std::string max = (*std::max_element(_db.begin(), _db.end())).first;
	int year = BitcoinExchange::strtoi(date.substr(0, 4));
	int month = BitcoinExchange::strtoi(date.substr(5, 2));
	int day = BitcoinExchange::strtoi(date.substr(8, 2));
	check = (date >= min && date <= max) && (month >= 1 && month <= 12);
	check = check && (day >= 1 && day <= 31);//!!!February
	// std::cout << day << std::endl;
	// if ()
	return(check);
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
		// std::cout << date << " "<< string_val << std::fixed << std::setprecision(2) <<  this->strtof(string_val) << std::endl;
	}
	

	// std::spli
	
	//_db[key] = value
	// std::cout << "fggd\n";
}

float BitcoinExchange::getRate(std::string date)
{
	std::map<std::string, float>::iterator it;
	it = _db.find(date);
	if (it != _db.end())
		return(it->second);
	else
		return(100000);
	//implement close date
}

/*DESTRUCTOR*/
BitcoinExchange::~BitcoinExchange(){}
