/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:34:27 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 11:37:45 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45)
	, target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj)
	: AForm(obj)
{
	this->target = obj.target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::executer() const
{
	srand(std::time(0));
	std::cout << "TTRTtrRRrrTTTRRRRRrrrrrTtttTRR....\n";
	if ((rand() % 2) != 0)
		std::cout << this->target+" has been robotomized sucessfully" << std::endl;
	else
		std::cout << "Failed to robotomized "+this->target << std::endl;
}