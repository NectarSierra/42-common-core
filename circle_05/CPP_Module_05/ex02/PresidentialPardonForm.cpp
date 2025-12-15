/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:35:07 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 11:50:17 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (std::string target)
	: AForm("PresidentialPardonForm", 25, 5)
	, target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: AForm(obj)
{
	this->target = obj.target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

void PresidentialPardonForm::executer() const
{
	std::cout << this->target+" has been pardoned by Zaphod Beeblebrox" << std::endl;
}