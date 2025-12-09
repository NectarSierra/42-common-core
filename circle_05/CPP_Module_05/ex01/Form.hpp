/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 06:41:41 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/09 09:25:36 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int required_to_sign;
		const int required_to_execute;
	public:
		Form(void);
		Form(std::string r_name, int r_to_sign, int r_to_execute);
		Form(const Form& obj);
		~Form();
	private:
		Form& operator=(Form& obj);
	public:
		std::string getName(void) const;
		bool getSignature(void) const;
		int getGradeRequiredToSign(void) const;
		int getGradeRequiredToExecute(void) const;
		void beSigned(Bureaucrat& obj);

	class GradeTooHighException : public std::exception
	{
		private:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& stream, Form& obj);

#endif