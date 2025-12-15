/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:57:11 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 09:18:46 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	Bureaucrat user_lambda("Lambda", 150);
	// Bureaucrat user_root("Root", 1);

	PresidentialPardonForm Presidential("Presidential");
	PresidentialPardonForm test(Presidential);
	std::cout << Presidential << "\n";
	std::cout << test;

	return (0);
}