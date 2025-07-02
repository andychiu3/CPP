#include "BitcoinExchange.hpp"

// constructor
BitcoinExchange::BitcoinExchange() {
	loadRateDB("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	_rateDB = copy._rateDB;
}

BitcoinExchange::~BitcoinExchange() {}

// operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_rateDB = other._rateDB;
	}
	return *this;
}

// getter
const std::map<std::string, double>& BitcoinExchange::getRateMap() const {
	return _rateDB;
}

bool	BitcoinExchange::isValidForm(std::string line, std::string deli) {
	// std::cout << line.size() << std::endl;
	int	l = deli.size();
	if (line.size() < static_cast<std::string::size_type>(10 + l + 1))
		return false;
	// std::cout << "length" << std::endl;
		
	if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]) || line[4] != '-'
	|| !isdigit(line[5]) || !isdigit(line[6]) || line[7] != '-'
	|| !isdigit(line[8]) || !isdigit(line[9]))
		return false;
	// std::cout << "pass date form err" << std::endl;
	
	if (line.substr(10, l) != deli)
		return false;
	// std::cout << "pass deli after err" << std::endl;

	std::string	amount = line.substr(line.find(deli) + deli.size());
	// std::cout << amount << std::endl;
	if (amount.empty())
		return false;
	char	*endptr;
	double	d = strtod(amount.c_str(), &endptr);
	if (*endptr || (d == 0 && amount != "0"))
		return false;
	// std::cout << "pass amount" << std::endl;

	return true;
}

bool	BitcoinExchange::isValidDate(std::string line) {
	int	year = atoi(line.substr(0, 4).c_str());
	int	month = atoi(line.substr(5, 2).c_str());
	int	day = atoi(line.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int	dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		dayInMonth[1] = 29;
	if (day < 1 || day > dayInMonth[month - 1])
		return false;

	return true;
}

bool	BitcoinExchange::isValidAmount(std::string line) {
	char	*endptr;
	double	btcAmount = strtod(line.substr(13).c_str(), &endptr);
	if (btcAmount < 0) {
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	if (btcAmount > 1000) {
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}

// takes form: CSV
void	BitcoinExchange::loadRateDB(const std::string& DBName) {
	if (DBName.empty())
		return ;
	
	std::ifstream	file(DBName.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: no rate data");
	
	std::string	line;
	std::getline(file, line);

	if (line != "date,exchange_rate")
		std::cerr << RED << "Error: rateDB format error line 1" << RESET << std::endl;
	
	for (size_t i = 2; std::getline(file, line); i++) {
		if (line.empty())
			continue ;
		if (!isValidForm(line, ",")) {
			std::cerr << RED << "Error: rateDB bad input: " << RESET << "line " << i << std::endl;
			continue ;
		}
		if (!isValidDate(line)) {
			std::cerr << RED << "Error: rateDB date format: " << RESET << "line " << i << std::endl;
			continue ;
		}
		
		char	*endptr;
		std::string	btcRateStr = line.substr(line.find(",") + 1);
		double	btcRate = strtod(btcRateStr.c_str(), &endptr);
		if (btcRate < 0) {
			std::cerr << RED << "Error: not a positive number: " << RESET << "line " << i << std::endl;
		}
		std::string	date = line.substr(0, 10);
		if (_rateDB.find(date) != _rateDB.end()) {
			std::cerr << RED << "Error: Duplicate date in DB: " << RESET << "line " << i << std::endl;
			continue ;
		}
		_rateDB.insert(std::make_pair(date, btcRate));
	}
}

double	BitcoinExchange::getRateForDate(const std::string& date) const {
	if (_rateDB.empty())
		return 0.0;

	std::map<std::string, double>::const_iterator	it = _rateDB.find(date);
	if (it != _rateDB.end()) {
		return it->second;
	}

	it = _rateDB.lower_bound(date);
	if (it == _rateDB.begin())
		return 0.0;
	if (it == _rateDB.end() || it->first > date)
		it--;
	return it->second;
}

void	BitcoinExchange::calcExchangeValue(const std::string& fileName) {
	if (fileName.empty())
		return ;
	
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	
	std::string	line;
	std::getline(file, line);

	if (line != "date | value")
	std::cerr << RED << "Error: format error line 1" << RESET << std::endl;

	while (std::getline(file, line)) {
		if (line.empty())
			continue ;
		if (!isValidForm(line, " | ")) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (!isValidDate(line)) {
			std::cerr << "Error: date format" << std::endl;
			continue ;
		}
		if (!isValidAmount(line))
			continue ;

		std::string	date = line.substr(0, line.find(" | "));
		std::string	valueStr = line.substr(line.find(" | ") + 3);
		double	amount = atof(valueStr.c_str());
		double	rate = getRateForDate(date);
		std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
	}
	file.close();
}

std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& btc) {
	const std::map<std::string, double>& rateMap = btc.getRateMap();
	std::map<std::string, double>::const_iterator	it = rateMap.begin();
	for (; it != rateMap.end(); it++) {
		os << it->first << "," << it->second << std::endl;
	}
	return os;
}
