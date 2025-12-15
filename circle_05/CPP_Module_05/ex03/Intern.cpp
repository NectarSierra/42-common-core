/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:52 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 14:41:31 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	int i;
	
	std::string forms[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	i = 0;
	while (i < 3 && forms[i] != form)
		i++;
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
	}
	throw NotFound();
}

Intern::~Intern()
{
	
}

const char* Intern::NotFound::what() const throw()
{
	return ("Exception: Form doesn't exsit");
}