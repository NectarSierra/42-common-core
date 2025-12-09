/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 06:52:15 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/09 10:26:30 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
	: name("")
	, required_to_sign(150)
	, required_to_execute(150)
{
	// std::cout << "AForm default constructor called!" << std::endl;
	this->is_signed = 0;
}

AForm::AForm(std::string r_name, int r_to_sign, int r_to_execute)
	: name(r_name)
	, required_to_sign(r_to_sign)
	, required_to_execute(r_to_execute)
{
	// std::cout << "AForm parameterized constructor called!" << std::endl;
	this->is_signed = 0;
	if (r_to_sign < 1 || r_to_execute < 1)
		throw GradeTooHighException();
	if (r_to_sign > 150 || r_to_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj)
	: name(obj.name)
	, required_to_sign(obj.required_to_sign)
	, required_to_execute(obj.required_to_execute)
{
	// std::cout << "AForm copy constructor called!" << std::endl;
	this->is_signed = obj.is_signed;
}

AForm::~AForm()
{
	// std::cout << "AForm desstructor called!" << std::endl;
}

std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getSignature(void) const
{
	return (this->is_signed);
}

int AForm::getGradeRequiredToSign(void) const
{
	return (this->required_to_sign);
}

int AForm::getGradeRequiredToExecute(void) const
{
	return (this->required_to_execute);
}

void AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= this->getGradeRequiredToSign())
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& stream, AForm& obj)
{
	stream << obj.getName() << ", AForm require grade of "
	<< obj.getGradeRequiredToSign() << " to be signed and grade of "
	<< obj.getGradeRequiredToExecute() << " to be executed";
	return (stream);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The current grade is too high\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The current grade is too low\n");
}