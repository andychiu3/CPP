#ifndef	BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

#include <cstdlib>

#define RED "\033[31m"
#define RESET "\033[0m"

class BitcoinExchange {
	private:
		std::map<std::string, double>	_rateDB;

	public:
		// structor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		// operator
		BitcoinExchange& operator=(const BitcoinExchange& other);

		// getter
		const std::map<std::string, double>& getRateMap() const;

		// is
		bool	isValidForm(std::string line, std::string deli);
		bool	isValidDate(std::string line);
		bool	isValidAmount(std::string line);

		void	loadRateDB(const std::string& DBName);
		double	getRateForDate(const std::string& date) const;
		void	calcExchangeValue(const std::string& fileName);
}	;

// debug
std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& btc);

#endif
