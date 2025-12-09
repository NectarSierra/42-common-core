/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:35:04 by nsaillez          #+#    #+#             */
/*   Updated: 2025/12/09 10:50:05 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPadonForm : public AForm
{
	public:
		PresidentialPadonForm(void);
		PresidentialPadonForm(std::string target);
		PresidentialPadonForm(const PresidentialPadonForm& obj);
		~PresidentialPadonForm();
	private:
		PresidentialPadonForm& operator=(const PresidentialPadonForm& obj);
};

#endif