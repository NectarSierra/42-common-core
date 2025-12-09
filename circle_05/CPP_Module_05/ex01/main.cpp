/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:57:11 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/09 09:25:54 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main( void )
{
	Bureaucrat user_lambda("Lambda", 150);
	Bureaucrat user_root("Root", 1);

	Form form_secret("Secret form", 1, 1);
	Form form_public("Public form", 150, 150);
	
	std::cout << user_lambda << std::endl;
	std::cout << user_root << std::endl;
	
	std::cout << std::endl;
	
	std::cout << form_secret << std::endl;
	std::cout << form_public << std::endl;

	std::cout << std::endl;
	
	user_lambda.signForm(form_secret);

	// form_secret.beSigned(user_lambda);
	try
	{
		form_secret.beSigned(user_lambda);
	}
	catch(const std::exception& exc)
	{
		std::cerr << exc.what() << '\n';
	}
	
	return (0);
}