/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:58:08 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/20 08:57:30 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename A>
void non_const_print(A& value)
{
	value += 1; 
	std::cout << value << std::endl;
}

template <typename A>
void const_print(const A& value)
{
	std::cout << value << std::endl;
}

template <typename A>
void iter(A *adrs,const size_t len, void (*f)(A&))
{
	for (size_t i = 0; i < len; i++)
		f(adrs[i]);
}

template <typename A>
void iter(const A *adrs ,const size_t len, void (*f)(const A&))
{
	for (size_t i = 0; i < len; i++)
		f(adrs[i]);
}
