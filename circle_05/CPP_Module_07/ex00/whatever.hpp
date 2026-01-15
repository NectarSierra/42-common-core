/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:40:13 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/15 14:54:28 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> void swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T> T min(T& a, T& b)
{
	return ((a < b) ? a : b);
}

template <typename T> T max(T& a, T& b)
{
	return ((a > b) ? a : b);
}