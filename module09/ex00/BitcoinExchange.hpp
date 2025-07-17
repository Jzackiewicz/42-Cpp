#pragma once

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<struct tm, float>	_rates;

		bool	_validateLine(std::string line);
		void	_loadExchangeRates(const char *filename);
		bool	_checkLine(const std::string &line) const;
		bool	_checkFile(std::ifstream &file) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

};