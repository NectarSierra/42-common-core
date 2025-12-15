/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:57:11 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 12:37:27 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	Bureaucrat user_lambda("Lambda", 150);
	Bureaucrat user_moderator("Moderator", 45);
	Bureaucrat user_vice_president("Vice_President", 25);
	Bureaucrat user_president("President", 5);
	Bureaucrat user_root("Root", 1);
	
	// Required grades: sign 25, exec 5
	PresidentialPardonForm Presidential("Mike flynn");
	
	// Required grades: sign 72, exec 45
	RobotomyRequestForm Roboto("Roboto");
	
	// Required grades: sign 145, exec 137
	ShrubberyCreationForm Shrubbery("4rbr3s");

	user_president.signForm(Presidential);
	user_president.executeForm(Presidential);

	std::cout << std::endl;
	
	user_lambda.signForm(Presidential);
	user_lambda.executeForm(Presidential);

	std::cout << std::endl;

	user_vice_president.signForm(Presidential);
	user_vice_president.executeForm(Presidential);

	std::cout << std::endl;

	user_moderator.signForm(Roboto);
	user_moderator.executeForm(Roboto);
	
	std::cout << std::endl;

	user_moderator.executeForm(Shrubbery);

	std::cout << std::endl;

	user_moderator.signForm(Shrubbery);
	user_moderator.executeForm(Shrubbery);

	return (0);
}