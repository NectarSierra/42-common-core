/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 06:52:15 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/09 09:25:33 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: name("")
	, required_to_sign(150)
	, required_to_execute(150)
{
	// std::cout << "Form default constructor called!" << std::endl;
	this->is_signed = 0;
}

Form::Form(std::string r_name, int r_to_sign, int r_to_execute)
	: name(r_name)
	, required_to_sign(r_to_sign)
	, required_to_execute(r_to_execute)
{
	// std::cout << "Form parameterized constructor called!" << std::endl;
	this->is_signed = 0;
	if (r_to_sign < 1 || r_to_execute < 1)
		throw GradeTooHighException();
	if (r_to_sign > 150 || r_to_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& obj)
	: name(obj.name)
	, required_to_sign(obj.required_to_sign)
	, required_to_execute(obj.required_to_execute)
{
	// std::cout << "Form copy constructor called!" << std::endl;
	this->is_signed = obj.is_signed;
}

Form::~Form()
{
	// std::cout << "Form desstructor called!" << std::endl;
}

std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getSignature(void) const
{
	return (this->is_signed);
}

int Form::getGradeRequiredToSign(void) const
{
	return (this->required_to_sign);
}

int Form::getGradeRequiredToExecute(void) const
{
	return (this->required_to_execute);
}

void Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= this->getGradeRequiredToSign())
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& stream, Form& obj)
{
	stream << obj.getName() << ", form require grade of "
	<< obj.getGradeRequiredToSign() << " to be signed and grade of "
	<< obj.getGradeRequiredToExecute() << " to be executed";
	return (stream);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The current grade is too high\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The current grade is too low\n");
}