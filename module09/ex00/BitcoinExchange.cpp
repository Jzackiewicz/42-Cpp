#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <climits>

BitcoinExchange::BitcoinExchange(void)
{
	this->_loadExchangeRates("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_rates = other._rates;
	return (*this);
}

void	BitcoinExchange::_loadExchangeRates(const char *filename)
{
	std::ifstream	file(filename);
	std::string		text;

	if (!Validator::_checkFile(file))
		return ;
	getline(file, text);
	while (getline(file, text))
	{
		if (!Validator::_checkLine(text, ","))
			continue ;
		else
			this->_rates.insert(BitcoinExchange::_extractPairFromLine(text, ","));
	}

}

void	BitcoinExchange::calculateValues(const char *filename) const
{
	std::ifstream					file(filename);
	std::string						text;
	std::pair<std::string, float>	curPair;

	if (!Validator::_checkFile(file))
		return ;
	getline(file, text);
	if (text != "date | value")
	{
		std::cerr << "Error: Wrong first line!" << std::endl;
		return ;
	}
	while (getline(file, text))
	{
		if (!Validator::_checkLine(text, " | "))
			continue ;
		else
		{
			curPair = BitcoinExchange::_extractPairFromLine(text, " | ");
			float rate = this->_getClosestDateRate(curPair.first);
			if (rate < 0)
				continue ;
			std::cout << curPair.first << " => " << curPair.second << " = " << rate * curPair.second << std::endl;
		}
	}
}

float	BitcoinExchange::_getClosestDateRate(const std::string &date) const
{
	std::map<std::string, float>::const_reverse_iterator it;

	for (it = this->_rates.rbegin(); it != this->_rates.rend(); ++it)
	{
		if (it->first <= date)
			return (it->second);
	}
	std::cerr << "Error: No exchange rate found for date => " << date << std::endl;
	return (-1.0f);
}

std::pair<std::string, float> BitcoinExchange::_extractPairFromLine(const std::string &line, const std::string &sep)
{
	std::pair<std::string, float>	newPair;
	std::string					date;
	std::string					exchangeRate;

	date = line.substr(0, line.find(sep));
	exchangeRate = line.substr(line.find(sep) + sep.length());
	newPair.first = date;
	newPair.second = static_cast<float>(std::atof(exchangeRate.c_str()));
	return (newPair);
}

bool	Validator::_checkDate(const std::string &date)
{
	struct tm	tm;
	
	if (date.empty())
		return (false);
	strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (tm.tm_mon + 1 < 0 || tm.tm_mon + 1 > 12)
        return (false);
	if (tm.tm_mday < 1 || tm.tm_mday > 31)
		return (false);
	if ((tm.tm_mon + 1 == 4 || tm.tm_mon + 1 == 6 || tm.tm_mon + 1 == 9 || tm.tm_mon + 1 == 11) && tm.tm_mday > 30)
		return (false);
	if (tm.tm_mon + 1 == 2)
	{
		if (((tm.tm_year + 1900) % 4 == 0 && (tm.tm_year + 1900) % 100 != 0) || ((tm.tm_year + 1900) % 400 == 0))
		{
			if (tm.tm_mday > 29)
				return (false);
		}
		else
		{
			if (tm.tm_mday > 28)
				return (false);
		}
	}
	return (true);
}

bool	Validator::_checkValue(const std::string &value)
{
	float exchangeRateNum;

	if (value.empty())
		return (false);
	for (size_t i = 0; i < value.length(); ++i)
	{
		if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
		{
			std::cerr << "Error: not a number =>" << value << std::endl;
			return (false);
		}
	}
	exchangeRateNum = static_cast<float>(std::atof(value.c_str()));
	if (exchangeRateNum < 0 || exchangeRateNum > 1000)
	{
		std::cerr << "Error: number not in correct range (0-1000) => " << value << std::endl;
		return (false);
	}
	return (true);
}

bool	Validator::_checkLine(const std::string &line, const std::string &sep)
{
	std::string	date;
	std::string	value;

	date = line.substr(0, line.find(sep));
	if (!Validator::_checkDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return (false);
	}
	value = line.substr(line.find(sep) + sep.length());
	if (line.find(sep) == std::string::npos)
		value = "0";
	if (sep == " | ")
	{
		if (!Validator::_checkValue(value))
			return (false);
	}
	return (true);
}

bool	Validator::_checkFile(std::ifstream &file)
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

void	BitcoinExchange::printMap()
{
	std::map<std::string, float>::iterator it;

	for (it = _rates.begin(); it != _rates.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

Validator::Validator() {}

Validator::~Validator() {}

Validator::Validator(const Validator &){}

Validator &Validator::operator=(const Validator &)
{
	return (*this);
}
