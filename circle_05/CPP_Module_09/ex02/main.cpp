/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:06:26 by nsaillez          #+#    #+#             */
/*   Updated: 2026/07/19 16:36:18 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <vector>
#include <string_view>

int strtol_checker(char *str)
{
	char* end;
	long tmp;
	
	tmp = strtol(str, &end, 0);
	if (*end != '\0' || end == str)
	{
		std::cout << "\033[31mError: Non-digit detected\033[0m" << std::endl;
		return (-1);
	}
	if (tmp < 0)
	{
		std::cerr << "\033[31mError: Negative number detected\033[0m" << std::endl;
		return (-1);
	}
	if (errno == ERANGE || tmp > __INT_MAX__)
	{
		std::cerr << "\033[31mError: Overflow detected\033[0m" << std::endl;
		return (-1);
	}
	return (static_cast<int>(tmp));
}

int parser(int argc, char** argv, std::vector<int> &arr)
{
	for (int i = 1; i < argc; i++)
	{
		int tmp = strtol_checker(argv[i]);
		if (tmp < 0)
			return (-1);
		for (int j = 0; static_cast<size_t>(j) < arr.size(); j++)
		{
			if ((i - 1) != j && tmp == arr[j])
			{
				std::cout << "\033[31mError: Duplicates detected\033[0m" << std::endl;
				return (-1);
			}
		}
		arr.push_back(tmp);
	}
	return (0);
}

std::vector<pairs> merge(std::vector<pairs> left, std::vector<pairs> right)
{
    std::vector<pairs> res;

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

std::vector<pairs> rec_largest(std::vector<pairs> arr)
{
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2;

    std::vector<pairs> left(arr.begin(), arr.begin() + mid);
    std::vector<pairs> right(arr.begin() + mid, arr.end());

    left = rec_largest(left);
    right = rec_largest(right);

    return (merge(left, right));
}

std::vector<pairs> create_pairs(std::vector<int>& unsorted_numbers, int& unpaired)
{
	std::vector<pairs> arr1;
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
	return (arr1);
}

std::vector<int> jacobsthal_sequence(int n)
{
    std::vector<int> seq;
	
    seq.push_back(0);
    seq.push_back(1);
	if (n < 2)
		n = 2;
	while(seq.back() < n)
    {
        int next = seq[seq.size()-1] + 2 * seq[seq.size()-2];
        seq.push_back(next);
    }
    return (seq);
}


int binary_sort(std::vector<int> main_chain, int n)
{
	int low;
	int high;
	int mid;

	for (size_t i = 0; i < main_chain.size(); i++)
	low = 0;
	high = main_chain.size();
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

#include <sys/time.h>
#include <list>

int	main(int argc, char **argv)
{
	timeval start, end;
	if (argc < 2)
	{
		std::cerr << "\033[31mError: Wrong use of program!\033[0m" << std::endl;
		return (1);
	}
	std::vector<int> unsorted_numbers;
	if (parser(argc, argv, unsorted_numbers))
		return (-1);
	
	/*--------------------------------------------------------------*/
	
	std::cout << "Before:";
	for (int i = 0; i < argc - 1; i++)
		std::cout << " " << unsorted_numbers[i];
	std::cout << std::endl;

	int	unpaired = -1;
	std::vector<pairs> arr1;
	// std::list<pairs> arr2;
	arr1 = create_pairs(unsorted_numbers, unpaired);
	// arr2 = create_pairs(unsorted_numbers, unpaired);
	
	gettimeofday(&start, NULL);
	std::vector<pairs> res = rec_largest(arr1);

	/* ------------------------------------------------------------ */

	std::vector<int> main_chain;
	for (size_t i = 0; i < res.size(); i++)
		main_chain.push_back(res[i].largest);
	
	if (res.size() != 0)
		main_chain.insert(main_chain.begin(), res[0].smallest);
	
	std::vector<int> jac_seq;
	int highest;
	int lowest;
	
	jac_seq = jacobsthal_sequence(res.size());

	std::vector<int>::iterator it;
	
	for (size_t i = 2; jac_seq[i] < (int)res.size() && res.size() > 0; i++)
	{
		highest = jac_seq[i+1]-1; 
		lowest = jac_seq[i];
		if (highest > (int)res.size()-1)
			highest = res.size()-1;
		
		for (int j = highest; j >= lowest; j--)
		{
			it = main_chain.begin() + binary_sort(main_chain, res[j].smallest);
			main_chain.insert(it, res[j].smallest);
		}
		
		// std::cout << highest << "..." << lowest << std::endl;
		// std::cout << res[highest].smallest << "->" << res[lowest].smallest << std::endl;
	}
	if (unpaired != -1)
	{
		if (main_chain.size() == 0)
			main_chain.insert(main_chain.begin(), unpaired);
		else
		{			
			it = main_chain.begin() + binary_sort(main_chain, unpaired);
			main_chain.insert(it, unpaired);
		}
	}
	gettimeofday(&end, NULL);
	long long us = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	
	std::cout << "After:  ";
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << main_chain.size() << " elements with \033[32mstd::vector\033[0m : "<< us << " us" << std::endl;
	
	return (0);
}