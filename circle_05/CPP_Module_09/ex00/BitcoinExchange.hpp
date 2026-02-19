/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:00:21 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/19 13:30:10 by nsaillez         ###   ########.fr       */
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
	BitcoinExchange(const std::string db_path);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

	static std::pair<std::string, float> get_pair(std::ifstream& f_stream);
};

#endif