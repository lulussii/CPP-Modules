/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:45:52 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/13 15:00:30 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "---- TEST 1 : MutantStack basics ----" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element before pop: " << mstack.top() << std::endl;
	std::cout << "Size of mstack: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Top element after pop: " << mstack.top() << std::endl;
	std::cout << "Size of mstack: " << mstack.size() << "\n" << std::endl;


	mstack.push(3);
	mstack.push(4);
	mstack.push(19);
	mstack.push(7);

	MutantStack<int>::iterator begin = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	std::cout << "Stack content through iteration: " << std::endl;
	while (begin != end)
	{
		std::cout << "- " << *begin << std::endl;
		++begin; 
	}
	
	std::cout << "\n---- TEST 2 : Comparison with std::list ---- " << std::endl;
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(3);
	mlist.push_back(4);
	mlist.push_back(19);
	mlist.push_back(7);

	std::list<int>::iterator lbegin = mlist.begin();
	std::list<int>::iterator lend = mlist.end();
	
	std::cout << "List content :" << std::endl;
	while (lbegin != lend)
	{
		std::cout << "- " << *lbegin << std::endl;
		++lbegin;
	}

	return 0;
}