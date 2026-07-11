/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:06:26 by nsaillez          #+#    #+#             */
/*   Updated: 2026/07/11 08:34:25 by nsaillez         ###   ########.fr       */
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


	int	unpaired = -1;
	std::vector<pairs> arr1;
	arr1 = create_pairs(unsorted_numbers, unpaired);
	
	std::vector<pairs> res = rec_largest(arr1);
	for (size_t i = 0; i < (res.size()); i++)
	{
		std::cout << "(" << res[i].smallest << ", " << res[i].largest << ")" << std::endl;
	}
	if (unpaired != -1)
	{
		std::cout << "Unpaired: " << unpaired << std::endl;
	}
	return (0);
}