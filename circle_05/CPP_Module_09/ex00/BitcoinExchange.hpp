/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:00:21 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/24 13:41:54 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

class BitcoinExchange
{
private:
	const std::string				db_path;
	std::map<std::string, float>	btc_history_db;
public:
	BitcoinExchange(const std::string db_path, const std::string input);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

	std::pair<std::string, float> mysearch(std::string date_search);

	static std::pair<std::string, float> get_pair(std::ifstream& f_stream);
};

#endif