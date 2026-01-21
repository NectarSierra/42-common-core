/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 08:48:00 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/21 12:07:52 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 750

int main()
{
	// My tests:
	std::cout << "Array of size 0:" << std::endl;
	Array<int> zero_array;
	zero_array.print_arr();

	std::cout << std::endl << "Array of size 3:" << std::endl;
	Array<int> three_array(3);
	three_array.print_arr();

	std::cout << std::endl << "Copy of an array:" << std::endl;
	Array<int> copy_array(three_array);
	std::cout << "Copy array:" << std::endl;
	copy_array.print_arr();
	std::cout << "Original array:" << std::endl;
	three_array.print_arr();
	std::cout << std::endl << "~Modification to original array~" << std::endl;
	three_array.add_one_to_all();
	std::cout << "Copy array:" << std::endl;
	copy_array.print_arr();
	std::cout << "Original array:" << std::endl;
	three_array.print_arr();

	std::cout << std::endl << "Access to a specified index:" << std::endl;
	std::cout << std::endl << "~Modification to original array index 1 by 100~" << std::endl;
	three_array[1] = 100;
	three_array.print_arr();
	std::cout << std::endl << "~Modification to copy array index 1 by original array index 1~" << std::endl;
	copy_array[1] = three_array[1];
	copy_array.print_arr();
	std::cout << std::endl;

	// Subject tests:
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;	
	return (0);
}