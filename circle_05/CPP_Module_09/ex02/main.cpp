/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:19:19 by nsaillez          #+#    #+#             */
/*   Updated: 2026/05/21 11:21:59 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

struct pairs
{
	int largest;
	int smallest;
};

std::vector<pairs> rec_largest(std::vector<pairs>& arr, size_t stack_size)
{
	int count = 0;
	
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[count].largest < arr[(count + stack_size)].largest)
		{
			std::cout << count << "<->" << (count + stack_size) << std::endl;
			std::swap(arr[count].largest, arr[(count + stack_size)].largest);
		}
		count += (stack_size*2);
	}
	if (stack_size < arr.size())
		return(rec_largest(arr, (stack_size * 2)));
	return (arr);
}

int	main(int argc, char **argv)
{
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

	
	// pairs
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
		}
		else
		{
			tmp.largest = -1; // since undefined -1
			tmp.smallest = unsorted_numbers[i];
		}
		std::cout << "(" << tmp.largest << ", " << tmp.smallest << ")" << std::endl;
		arr1.push_back(tmp);
	}
	rec_largest(arr1, 1);
	for (size_t i = 0; i < arr1.size(); i++)
	{
		std::cout << "(" << arr1[i].largest << ", " << arr1[i].smallest << ")" << std::endl;
	}
	// tris of largest (recursive)
	return (0);
}