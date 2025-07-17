#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
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

	if (!this->_checkFile(file))
		return ;
	while (getline(file, text))
	{
		if (!this->_checkLine(text))
			continue;
		else
			return;
	}

}

bool	BitcoinExchange::_checkLine(const std::string &line) const
{
	struct tm	tm;
	std::string	date;
	std::string	exchangeRate;

	date = line.substr(0, line.find(","));
	exchangeRate = line.substr(line.find(",") + 1);
	if (line.find(",") == std::string::npos ||
		date.empty() || exchangeRate.empty() ||
		!strptime(date.c_str(), "%Y-%m-%d", &tm))
		return (false);
	return (true);
}

bool	BitcoinExchange::_checkFile(std::ifstream &file) const
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