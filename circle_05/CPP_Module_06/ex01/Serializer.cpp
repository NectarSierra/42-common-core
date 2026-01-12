/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:48:56 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/12 11:51:43 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "iostream"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *result = reinterpret_cast<Data *>(raw);
	return (result);
}