/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:20:15 by nsaillez          #+#    #+#             */
/*   Updated: 2026/07/20 15:24:46 by nsaillez         ###   ########.fr       */
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
	if (this != &other)
	{
		this->container = other.container;
	}	
	return (*this);
}

template<typename C>
C PmergeMe<C>::merge(C left, C right)
{
    C res;

    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i].largest < right[j].largest)
            res.push_back(left[i++]);
        else
            res.push_back(right[j++]);
    }

    while (i < left.size())
        res.push_back(left[i++]);

    while (j < right.size())
        res.push_back(right[j++]);

    return (res);
}

template<typename C>
C PmergeMe<C>::rec_largest(C arr)
{
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2;

    C left(arr.begin(), arr.begin() + mid);
    C right(arr.begin() + mid, arr.end());

    left = rec_largest(left);
    right = rec_largest(right);

    return (merge(left, right));
}

template<typename C>
void PmergeMe<C>::create_pairs(std::vector<int>& unsorted_numbers, int& unpaired)
{
	C arr1;
	pairs tmp;
	for (size_t i = 0; i < unsorted_numbers.size(); i += 2)
	{
		if (i + 1 != unsorted_numbers.size())
		{
			if (unsorted_numbers[i] > unsorted_numbers[i + 1])
			{
				tmp.largest = unsorted_numbers[i];
				tmp.smallest = unsorted_numbers[i + 1];
			}
			else
			{
				tmp.largest = unsorted_numbers[i + 1];
				tmp.smallest = unsorted_numbers[i];
			}
			arr1.push_back(tmp);
		}
		else
			unpaired = unsorted_numbers[i];
	}
	this->container = arr1;
}

template<typename C>
int PmergeMe<C>::binary_sort(std::vector<int> main_chain, int n, int high)
{
	int low;
	int mid;

	for (size_t i = 0; i < main_chain.size(); i++)
	low = 0;
	while (high != low)
	{
		mid = main_chain[(low+high)/2];
		if (n > mid)
			low = (low+high)/2+1;
		else
			high = (low+high)/2;
	}
	return (low);
}

template<typename C>
std::vector<int> PmergeMe<C>::smallest_insertion(C vecArrLargest, PmergeMe<C> vecArr, int &unpaired, std::vector<int> jcb_sq)
{
	std::vector<int> main_chain;
	std::vector<int> pos_largest;
	
	for (size_t i = 0; i < vecArrLargest.size(); i++)
		pos_largest.push_back(i + 1);
	

	for (size_t i = 0; i < vecArrLargest.size(); i++)
		main_chain.push_back(vecArrLargest[i].largest);
	
	if (vecArrLargest.size() != 0)
		main_chain.insert(main_chain.begin(), vecArrLargest[0].smallest);
	
	int highest;
	int lowest;
	
	std::vector<int>::iterator it;
	
	for (size_t i = 2; jcb_sq[i] < (int)vecArrLargest.size() && vecArrLargest.size() > 0; i++)
	{
		highest = jcb_sq[i+1]-1; 
		lowest = jcb_sq[i];
		if (highest > (int)vecArrLargest.size()-1)
			highest = vecArrLargest.size()-1;
		
		for (int j = highest; j >= lowest; j--)
		{
			int place = vecArr.binary_sort(main_chain, vecArrLargest[j].smallest, pos_largest[j]);
			it = main_chain.begin() + place;
			for (size_t k = 0; k < pos_largest.size(); k++)
			{
				if (place <= pos_largest[k])
					pos_largest[k] += 1;
			}
			main_chain.insert(it, vecArrLargest[j].smallest);
		}
	}
	if (unpaired != -1)
	{
		if (main_chain.size() == 0)
			main_chain.insert(main_chain.begin(), unpaired);
		else
		{			
			it = main_chain.begin() + vecArr.binary_sort(main_chain, unpaired, main_chain.size());
			main_chain.insert(it, unpaired);
		}
	}
	return (main_chain);
}

template<typename C>
C PmergeMe<C>::get_container()
{
	return (this->container);
}

#include <deque>

template class PmergeMe<std::vector<pairs> >;
template class PmergeMe<std::deque<pairs> >;