/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:06:26 by nsaillez          #+#    #+#             */
/*   Updated: 2026/07/21 19:07:49 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <string_view>
#include <sys/time.h>

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

int	main(int argc, char **argv)
{
	timespec tstart, tend, tstart2, tend2;
	if (argc < 2)
	{
		std::cerr << "\033[31mError: Wrong use of program!\033[0m" << std::endl;
		return (1);
	}
	std::vector<int> unsorted_numbers;
	if (parser(argc, argv, unsorted_numbers))
		return (-1);
	
	
	std::cout << "Before:";
	for (int i = 0; i < argc - 1; i++)
		std::cout << " " << unsorted_numbers[i];
	std::cout << std::endl;
	
	std::vector<pairs> arr1;
	std::deque<pairs> arr2;
	
	PmergeMe<std::vector<pairs>, std::vector<int> > vecArr(arr1);
	PmergeMe<std::deque<pairs>, std::deque<int> > dequeArr(arr2);

	int	unpaired = -1;
	
	vecArr.create_pairs(unsorted_numbers, unpaired);
	dequeArr.create_pairs(unsorted_numbers, unpaired);
	
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	std::vector<pairs> vecArrLargest = vecArr.rec_largest(vecArr.get_container());
	std::vector<int> jcb_seq = jacobsthal_sequence(vecArrLargest.size());
	std::vector<int> main_chain;
	vecArr.smallest_insertion(vecArrLargest, vecArr, unpaired, jcb_seq, main_chain);
	clock_gettime(CLOCK_MONOTONIC, &tend);

	clock_gettime(CLOCK_MONOTONIC, &tstart2);
	std::deque<pairs> dequeArrLargest = dequeArr.rec_largest(dequeArr.get_container());
	std::vector<int> jcb_seq2 = jacobsthal_sequence(dequeArrLargest.size());
	std::deque<int> main_chain2;
	dequeArr.smallest_insertion(dequeArrLargest, dequeArr, unpaired, jcb_seq, main_chain2);
	clock_gettime(CLOCK_MONOTONIC, &tend2);
	
	
	long long us = (long long)(tend.tv_sec - tstart.tv_sec) * 1000000LL + (long long)(tend.tv_nsec - tstart.tv_nsec) / 1000LL;	
	long long us2= (long long)(tend2.tv_sec - tstart2.tv_sec) * 1000000LL + (long long)(tend2.tv_nsec - tstart2.tv_nsec) / 1000LL;

	std::cout << "After:  ";
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << main_chain.size() << " elements with \033[32mstd::vector\033[0m : "<< us << " us" << std::endl;
	std::cout << "Time to process a range of " << main_chain.size() << " elements with \033[32mstd::deque\033[0m : "<< us2 << " us" << std::endl;
	return (0);
}