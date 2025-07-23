#pragma once

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_rates;

		void		_loadExchangeRates(const char *filename);
		float		_getClosestDateRate(const std::string &date) const;
		static std::pair<std::string, float> _extractPairFromLine(const std::string &line, const std::string &sep);
		
	public:
		BitcoinExchange(void);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		void	printMap(void);
		void	calculateValues(const char *filename) const;

};

class Validator
{
	private:
		Validator();
		~Validator();
		Validator(const Validator &other);
		Validator &operator=(const Validator &other);
	
	public:
		static bool	checkDate(const std::string &date);
		static bool	checkValue(const std::string &value);
		static bool	checkLine(const std::string &line, const std::string &sep);
		static bool	checkFile(std::ifstream &file);
};
