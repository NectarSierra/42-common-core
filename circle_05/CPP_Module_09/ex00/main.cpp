/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:14:41 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/19 12:16:01 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>

std::pair<std::string, float> get_pair(std::string line)
{
	std::string date;
	std::string exch_rate;
	float exch_rate_uint = 0;

	std::string::iterator it = line.begin();
	while(it != line.end())
	{
		if (*it == ',')
		{
			it++;
			break;
		}
		date.push_back(*it);
		it++;
	}
	while(it != line.end())
	{
		exch_rate.push_back(*it);
		it++;
	}
	exch_rate_uint = atof(exch_rate.c_str());
	return (std::pair<std::string, float>(date, exch_rate_uint));
}

int get_btc_history(char* f_path, std::map<std::string, float>& btc_history)
{
	std::string		line;
	std::ifstream	f_stream(f_path);
	
	if (!f_stream)
	{
		std::cerr << "\033[31m" << "[Error] " << "\033[0m" << "Could not open file." << std::endl;
		return -1;
	}
	getline(f_stream, line); // skip 1st line;
	while (getline(f_stream, line))
	{
		btc_history.insert(get_pair(line));
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::map<std::string, float> btc_history;
	std::map<std::string, float>::iterator it;
	
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "[Error] " << "\033[0m" << "Wrong usage of program, please use => ./btc [FILE]" << std::endl;
		return (-1);
	}
	else
	{
		if (get_btc_history(argv[1], btc_history))
			return (-1);
	}

	std::string search = "2000-05-31";
	it = btc_history.find(search);
	if (it == btc_history.end())
	{
		std::cerr << "\033[33m" << "[Debug Warning] " << "\033[0m" << "Could not find element. Returning the lower closest one." << std::endl;
		it = btc_history.lower_bound(search);
		if (it == btc_history.end())
			it--;
	}
	std::cout << "DATE: " << it->first << std::endl;
	std::cout << "EXCHANGE_R: " << it->second << std::endl;
}