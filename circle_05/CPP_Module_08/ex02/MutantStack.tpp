/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:06:43 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/10 18:11:04 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T, class C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::begin() const
{
	return (std::stack<T, C>::c.begin());
}

template <class T, class C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::end() const
{
	return (std::stack<T, C>::c.end());
}

template <class T, class C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin()
{
	return (std::stack<T, C>::c.begin());
}

template <class T, class C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end()
{
	return (std::stack<T, C>::c.end());
}