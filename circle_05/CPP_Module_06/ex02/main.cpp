/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:18 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/13 09:13:32 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	A a = A();
	Base& a_ref = a;
	Base::identify(a_ref);
	
	Base* generated = Base::generate();
	Base& generated_ref = *generated;
	Base::identify(generated);
	Base::identify(generated_ref);
	return (0);
}