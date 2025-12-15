/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:57:11 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 11:13:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	Bureaucrat user_lambda("Lambda", 1);
	// Bureaucrat user_root("Root", 1);

	//AForm teskt("ok", 1, 1);

	PresidentialPardonForm Presidential("Presidential");
	PresidentialPardonForm test(Presidential);
	std::cout << Presidential << "\n";
	std::cout << test << "\n";

	Presidential.beSigned(user_lambda);
	user_lambda.executeForm(Presidential);

	return (0);
}