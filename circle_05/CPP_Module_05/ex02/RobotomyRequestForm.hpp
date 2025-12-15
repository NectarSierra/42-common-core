/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:34:29 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/15 11:27:14 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& obj);
		~RobotomyRequestForm();
	private:
		RobotomyRequestForm& operator=(RobotomyRequestForm& obj);
	public:
		virtual void executer() const;
};

#endif