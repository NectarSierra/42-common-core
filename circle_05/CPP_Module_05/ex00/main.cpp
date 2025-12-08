/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:57:11 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/08 18:11:53 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat a;
	std::cout << a << std::endl;
	
	Bureaucrat b("Julien", 54);
	std::cout << b << std::endl;
	
	Bureaucrat c("Noah", 150);
	std::cout << c << std::endl;

	Bureaucrat d("Lola", 1);
	std::cout << d << std::endl;

	try
	{
		Bureaucrat e("Frederic", 151);
		std::cout << e << std::endl;
	}
	catch (std::exception& exc)
	{
		std::cout << "Caught: " << exc.what();
	}

	try
	{
		d.incrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception& exc)
	{
		std::cout << "Caught: " << exc.what();
	}

	try
	{
		c.decrementGrade();
		std::cout << c << std::endl;
	}
	catch (std::exception& exc)
	{
		std::cout << "Caught: " << exc.what();
	}
	
	return (0);
}