/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:20:31 by nsaillez          #+#    #+#             */
/*   Updated: 2026/05/19 09:06:14 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

class PmergeMe
{
public:
	PmergeMe(const std::vector<int> &arr);
	
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe operator=(const PmergeMe &other);
};