/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:00:04 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/19 13:32:51 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::pair<std::string, float> BitcoinExchange::get_pair(std::ifstream& f_stream)
{
	std::string date = "";
	std::string exch_rate_s = "";
	float 		exch_rate = 0;

	getline(f_stream, date, ',');
	getline(f_stream, exch_rate_s);
	exch_rate = atof(exch_rate_s.c_str());
	return (std::pair<std::string, float>(date, exch_rate));
}

BitcoinExchange::BitcoinExchange(const std::string db_path) : db_path(db_path)
{
	std::string		line;
	std::ifstream	f_stream(db_path.c_str());
	if (!f_stream)
	{
		std::cerr << "\033[31m" << "[Error] " << "\033[0m" << "Could not open file." << std::endl;
		return;
	}
	getline(f_stream, line); /* skip 1st line */
	while (getline(f_stream, line))
		btc_history_db.insert(get_pair(f_stream));

	// /* ------------------------------------- */

	// std::string search = "2022-03-30";
	// std::map<std::string, float>::iterator it;
	// it = btc_history_db.find(search);
	// if (it == btc_history_db.end())
	// {
	// 	std::cerr << "\033[33m" << "[Debug Warning] " << "\033[0m" << "Could not find element. Returning the lower closest one." << std::endl;
	// 	it = btc_history_db.lower_bound(search);
	// 	if (it == btc_history_db.end())
	// 		it--;
	// }
	// std::cout << "DATE: " << it->first << std::endl;
	// std::cout << "EXCHANGE_R: " << it->second << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	this->btc_history_db = other.btc_history_db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	
}