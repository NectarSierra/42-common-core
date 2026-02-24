/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:00:04 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/24 12:58:47 by nsaillez         ###   ########.fr       */
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

bool str_isdigit(std::string input)
{
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (isdigit(*it) == 0)
			return (false);
	}
	
	return (true);
}

bool is_value_valid(std::string value)
{
	float f_value;
	bool	is_neg = false;
	bool	dot = false;

	for (std::string::iterator it = value.begin(); it != value.end(); it++)
	{
		if (*it == '-' && !is_neg)
		{
			is_neg = true;
			continue;
		}
		if (*it == '.' && !dot)
		{
			dot = true;
			continue;
		}
		if (isdigit(*it) == 0)
		{
			std::cerr << "\033[31mError:\033[0m Wrong value format\033[33m => \033[0m"<< value << std::endl;
			return (false);
		}
	}

	f_value = atof(value.c_str());
	if (f_value < 0)
	{
		std::cerr << "\033[31mError:\033[0m Not a positive number\033[33m => \033[0m"<< value << std::endl;
		return (false);
	}
	return (true);
}

bool is_date_valid(std::string date)
{
	std::string year;
	std::string month;
	std::string day;
	
	if (date.size() != 10)
		return (false);
	
	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);
	
	if (!str_isdigit(year) || !str_isdigit(month) || !str_isdigit(day))
		return (false);
	
	int tmp = atoi(month.c_str());
	if (tmp < 1 || tmp > 12)
		return (false);
	
	tmp = atoi(day.c_str());
	if (tmp < 1 || tmp > 31)
		return (false);
	return (true);
}

BitcoinExchange::BitcoinExchange(const std::string db_path, const std::string input) : db_path(db_path)
{
	std::string		line;
	std::ifstream	db_stream(db_path.c_str());
	if (!db_stream)
	{
		std::cerr << "\033[31m" << "[Error] " << "\033[0m" << "Could not open file: " << db_path << std::endl;
		return;
	}
	getline(db_stream, line); /* skip 1st line */
	while (getline(db_stream, line))
		btc_history_db.insert(get_pair(db_stream));

	/* -------------------------------------------- */

	std::string		date;
	std::string		value;

	std::string		year;
	std::string		month;
	std::string		day;
	
	std::ifstream	input_stream(input.c_str());
	if (!input_stream)
	{
		std::cerr << "\033[31m" << "[Error] " << "\033[0m" << "Could not open file: " << input << std::endl;
		return;
	}
	getline(input_stream, line); /* skip 1st line */
	while (getline(input_stream, line))
	{
		
		std::size_t found = line.find(" | ");
		if (found == std::string::npos)
		{
			std::cerr << "\033[31mError:\033[0m Bad input\033[33m => \033[0m"<< line << std::endl;
			continue;
		}
		
		date = line.substr(0, found);
		value = line.substr(found + 3);
		
		//std::cout << "date: " << date << std::endl;
		//std::cout << "value: " << value << std::endl;
		if (!is_date_valid(date))
		{
			std::cerr << "\033[31mError:\033[0m Bad date format\033[33m => \033[0m"<< date << std::endl;
			continue;
		}
		if (!is_value_valid(value))
		{
			//std::cerr << "\033[31mError:\033[0m Bad Value\033[33m => \033[0m"<< value << std::endl;
			continue;
		}
		std::cout << line << std::endl;
	}

	/* -------------------------------------------- */

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