/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:58:45 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/12 12:01:54 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data original;
	original.name = "ABC";
	original.value = 123;

	Data* original_ptr = &original;
	std::cout << "original_ptr: " << original_ptr;
	uintptr_t serialized = Serializer::serialize(original_ptr);
	std::cout << " -> serialized: " << serialized;
	Data* deserialized_ptr = Serializer::deserialize(serialized);
	std::cout << " -> deserialized_ptr: " << deserialized_ptr << std::endl;

	if (original_ptr != deserialized_ptr)
		std::cout << "original_ptr != deserialized_ptr" << "\n" << std::endl;
	else
		std::cout << "original_ptr == deserialized_ptr" << "\n" << std::endl;
	
	std::cout
	<< "original_ptr: " << original_ptr << "\n"
	<< "├─ name: " << original_ptr->name << "\n"
	<< "└─ value: " << original_ptr->value << "\n"
	<< std::endl;
	
	std::cout
	<< "deserialized_ptr: " << deserialized_ptr << "\n"
	<< "├─ name: " << deserialized_ptr->name << "\n"
	<< "└─ value: " << deserialized_ptr->value
	<< std::endl;
	
	return (0);
}