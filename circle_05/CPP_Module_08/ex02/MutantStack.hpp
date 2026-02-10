/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:06:22 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/10 09:58:18 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T, class A = std::stack<T> >
class MutantStack
{
	private:
	public:
		MutantStack();
		~MutantStack();
};

#include "MutantStack.tpp"

#endif
