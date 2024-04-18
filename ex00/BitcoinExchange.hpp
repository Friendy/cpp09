#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <iomanip>

typedef unsigned int u_int;

class BitcoinExchange {

private:
	std::string _entry;
	std::map<std::string, float> _db;

public:
	// const std::string getEntry() const;
	// void setEntry(std::string entry);

	void loadDB(const char *path);
	static float strtof(std::string str);
	void showEntries(u_int n);
	float getRate(std::string date);
	float findClose(std::string date);

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &original);
	BitcoinExchange &operator=(BitcoinExchange const &original);
	~BitcoinExchange();
};

#endif
