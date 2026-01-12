/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:10:28 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/12 15:12:39 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base* Base::generate(void)
{
	srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (0);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "object_type: A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "object_type: B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "object_type: C" << std::endl;
}

void Base::identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "object_type: A" << std::endl;
	if (dynamic_cast<B*>(&p))
		std::cout << "object_type: B" << std::endl;
	if (dynamic_cast<C*>(&p))
		std::cout << "object_type: C" << std::endl;
}