/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:26:05 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/21 11:15:45 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <iostream>

template <class T>
Array<T>::Array()
{
	this->array = new T[0];
	this->array_size = 0;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->array_size = n;
	for (unsigned int i = 0; i < this->size(); i++)
		this->array[i] = 0;
}

template <class T>
Array<T>::Array(Array<T>& other)
{
	this->array = new T[other.size()];
	this->array_size = other.size();
	for (unsigned int i = 0; i < other.size(); i++)
		this->array[i] = other.array[i];
}

template <class T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <class T>
Array<T>& Array<T>::operator=(Array<T>& other)
{
	this->array = new T[other.size()];
	this->array_size = other.size();
	for (unsigned int i = 0; i < other.size(); i++)
		this->array[i] = other.array[i];
	return (*this);
}

template <class T>
void Array<T>::add_one_to_all(void)
{
	for (unsigned int i = 0; i < this->size(); i++)
		this->array[i] += 1;
}

template <class T>
void Array<T>::print_arr(void)
{
	for (unsigned int i = 0; i < this->size(); i++)
		std::cout << this->array[i] << std::endl;
}

template <class T>
unsigned int Array<T>::size(void)
{
	return (this->array_size);
}

#endif