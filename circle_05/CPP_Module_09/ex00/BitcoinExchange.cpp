/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:00:04 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/15 11:52:38 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::pair<std::string, float> get_pair_from_line(const std::string& line)
{
	std::size_t comma = line.find(',');

	if (comma == std::string::npos)
		return (std::pair<std::string, float>("", 0));

	std::string date = line.substr(0, comma);
	std::string exch_rate_s = line.substr(comma + 1);

	float exch_rate = atof(exch_rate_s.c_str());

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
			std::cerr << "\033[31mError:\033[0m Bad value format\033[33m => \033[0m"<< value << std::endl;
			return (false);
		}
	}
	f_value = atof(value.c_str());
	if (value.size() > 4 || f_value > 1000)
	{
		std::cerr << "\033[31mError:\033[0m Value is too large\033[33m => \033[0m"<< value << std::endl;
		return (false);
	}
	if (f_value < 0)
	{
		std::cerr << "\033[31mError:\033[0m Value is negative\033[33m => \033[0m"<< value << std::endl;
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

std::pair<std::string, float> BitcoinExchange::mysearch(std::string date_search)
{
	std::map<std::string, float>::iterator it;
	it = btc_history_db.find(date_search);

	if (it == btc_history_db.end())
	{
		// std::cerr << "\033[33m" << "[Debug Warning] " << "\033[0m" << "Could not find element. Returning the lower closest one." << std::endl;
		it = btc_history_db.lower_bound(date_search);
		if (it == btc_history_db.end())
		{
			it--;
			return (*it);
		}
		if (it != btc_history_db.begin())
			it--;
	}
	return (*it);
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
   		btc_history_db.insert(get_pair_from_line(line));

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
		std::cout << date << " " << mysearch(date).first << " \033[30m=>\033[0m "  << value << " \033[30m=\033[0m " << mysearch(date).second*atof(value.c_str()) << std::endl;
		
	}

	/* -------------------------------------------- */

	
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