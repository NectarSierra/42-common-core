/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:17:11 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 08:46:53 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
typename T::iterator easyfind(T container, int needle)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw std::out_of_range("couldn't find occurence");
	else
		return (it);
}