#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>

BitcoinExchange::BitcoinExchange(const char *filename)
{
	this->_loadExchangeRates("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

void	BitcoinExchange::_loadExchangeRates(const char *filename)
{
	std::ifstream	file(filename);
	std::string		text;

	if (!BitcoinExchange::_checkFile(file))
		return ;
	while (getline(file, text))
	{
		if (!BitcoinExchange::_checkLine(text, ","))
			continue;
		else
			this->_rates.insert(BitcoinExchange::_extractPairFromLine(text, ","));
	}

}

void	BitcoinExchange::calculateValues(const char *filename) const
{
	std::ifstream	file(filename);
	std::string		text;

	if (!BitcoinExchange::_checkFile(file))
		return ;
	while (getline(file, text))
	{
		if (!BitcoinExchange::_checkLine(text, " | "))
			continue;
		else
	}

}

std::pair<std::string, float> BitcoinExchange::_extractPairFromLine(const std::string &line, const std::string &sep)
{
	std::pair<std::string, float>	newPair;
	std::string					date;
	std::string					exchangeRate;

	date = line.substr(0, line.find(sep));
	exchangeRate = line.substr(line.find(sep) + 1);
	newPair.first = date;
	newPair.second = static_cast<float>(std::atof(exchangeRate.c_str()));
	return (newPair);
}

bool	BitcoinExchange::_checkLine(const std::string &line, const std::string &sep)
{
	struct tm	tm;
	std::string	date;
	std::string	exchangeRate;
	char		*dateResult;

	date = line.substr(0, line.find(sep));
	exchangeRate = line.substr(line.find(sep) + 1);
	dateResult = strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (line.find(sep) == std::string::npos || !dateResult ||
		date.empty())
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::_checkFile(std::ifstream &file)
{
	if (!file.good())
	{
		std::cerr << "File cannot be opened!" << std::endl;
		return (false);
	}
	if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "File is empty!" << std::endl;
		return (false);
    }
	return (true);
}

void	BitcoinExchange::printMap(const std::string &mapName)
{
	std::map<std::string, float>::iterator it;

	if (mapName == "rates")
	{
		for (it = _rates.begin(); it != _rates.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	else
	{
		for (it = _values.begin(); it != _values.end(); ++it)
			std::cout << it->first << " <=> " << it->second << std::endl;
	}
}
