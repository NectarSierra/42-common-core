/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:57:16 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/09 08:26:02 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAU_CRAT_HPP
#define BUREAU_CRAT_HPP

#include <iostream>

class Bureaucrat 
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string r_name, int r_grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();
	private:
		Bureaucrat &operator=(const Bureaucrat &obj);
	
	public:
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

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

std::ostream &operator<<(std::ostream& stream, Bureaucrat& obj);

#endif