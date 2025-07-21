#pragma once

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_rates;

		void	_loadExchangeRates(const char *filename);
		static bool	_checkLine(const std::string &line, const std::string &sep);
		static bool	_checkFile(std::ifstream &file);
		static std::pair<std::string, float> _extractPairFromLine(const std::string &line, const std::string &sep);
		
		public:
		BitcoinExchange(const char *filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		void	printMap(const std::string &mapName);
		void	calculateValues(const char *filename) const;

};
