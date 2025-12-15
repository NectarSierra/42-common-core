/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:34:27 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 09:51:53 by nsaillez         ###   ########.fr       */
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

void RobotomyRequestForm::robotomyrequest()
{
	srand(std::time(0));
	std::cout << "TTRTtrRRrrTTTRRRRRrrrrrTtttTRR....\n";
	if ((rand() % 2) != 0)
		std::cout << this->target+" has been robotomized sucessfully";
	else
		std::cout << "Failed to robotomized "+this->target;
}