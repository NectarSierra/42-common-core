/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:57:11 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 15:37:48 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	Intern someRandomIntern;
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << "\n";
	
	rrf = someRandomIntern.makeForm("presidential pardon", "Spoonkid");
	std::cout << *rrf << "\n";

	// rrf = someRandomIntern.makeForm("ej1rgi5ut324r4re", "67");
	// std::cout << *rrf << "\n";
	
	return (0);
}