/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:28:15 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/20 09:33:38 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

class RPN
{
public:
	std::string expr;

	RPN(const std::string& input);
	RPN(const RPN& other);
	~RPN();
	RPN& operator= (const RPN& other);

	void calculate();
};
