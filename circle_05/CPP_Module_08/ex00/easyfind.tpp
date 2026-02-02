/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:17:11 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/02 13:59:55 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
typename T::iterator easyfind(T container, int index)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == index)
			return (it);
	}
	throw std::out_of_range("couldn't find occurence");
}