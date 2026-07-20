/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:20:31 by nsaillez          #+#    #+#             */
/*   Updated: 2026/07/20 13:27:40 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <vector>
#include <string_view>

struct pairs
{
	int largest;
	int smallest;
};

template <typename C>
class PmergeMe
{
private:
	C container;
public:
	PmergeMe(const C &arr);
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);
	
	C merge(C left, C right);
	C rec_largest(C arr);
	void create_pairs(std::vector<int>& unsorted_numbers, int& unpaired);
	int binary_sort(std::vector<int> main_chain, int n);
	std::vector<int> smallest_insertion(C vecArrLargest, PmergeMe vecArr, int &unpaired, std::vector<int> jcb_sq);

	C get_container();
};

#endif