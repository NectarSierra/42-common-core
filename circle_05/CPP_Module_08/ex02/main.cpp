/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:06:07 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/10 18:07:32 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MutantStack.hpp"

#include <deque>
#include <vector>
int main()
{
/*std::deque<int> mstack;
mstack.push_back(5);
mstack.push_back(17);
std::cout << mstack.back() << std::endl;
mstack.pop_back();
std::cout << mstack.size() << std::endl;
mstack.push_back(3);
mstack.push_back(5);
mstack.push_back(737);
//[...]
mstack.push_back(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;*/
/*std::stack<int, std::vector<int>> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
return 0;*/
MutantStack<int, std::vector<int> > mstack;
mstack.push(5);
mstack.push(17);
// std::cout << mstack.top() << std::endl;
mstack.pop();
// std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
const MutantStack<int, std::vector<int> > cstack(mstack);
MutantStack<int, std::vector<int> >::const_iterator c_it = cstack.begin();
MutantStack<int, std::vector<int> >::const_iterator c_ite = cstack.end();
++c_it;
--c_it;
while (c_it != c_ite)
{
std::cout << *c_it << std::endl;
++c_it;
}
return 0;
}