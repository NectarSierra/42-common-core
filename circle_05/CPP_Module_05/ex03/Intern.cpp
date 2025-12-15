/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:52 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 15:17:13 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

enum Forms{
	SHRUBERRY,
	ROBOTOMY,
	PRESIDENTIAL
};

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
		case SHRUBERRY:
			return (new ShrubberyCreationForm(target));
		case ROBOTOMY:
			return (new RobotomyRequestForm(target));
		case PRESIDENTIAL:
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