/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:20:15 by nsaillez          #+#    #+#             */
/*   Updated: 2026/07/19 16:16:49 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename C>
PmergeMe<C>::PmergeMe(const C &arr) : container(arr)
{
	
}

template<typename C>
PmergeMe<C>::PmergeMe(const PmergeMe<C> &other)
{
	*this = other;
}

template<typename C>
PmergeMe<C>::~PmergeMe()
{
	
}

template<typename C>
PmergeMe<C> &PmergeMe<C>::operator=(const PmergeMe<C> &other)
{
	if (this != other)
	{
		this->container = other.container;
	}	
	return (*this);
}