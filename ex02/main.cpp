/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:50:25 by tmurua            #+#    #+#             */
/*   Updated: 2026/06/01 17:51:56 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <stack>
#include <list>

int	main(void){
	MutantStack<int> mstack;

	std::cout << "--- Subject test example ---" << std::endl;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;

	mstack.pop(); // removes top element from stack (17)

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "--- MutantStack iteration ---" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it; // test that the iterator can move forward
	--it; // test that the iterator can move backward, back to begin()

	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "--- Copy into regular std::stack ---" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "copied stack size: " << s.size() << std::endl;

	std::cout << std::endl;

	std::cout << "--- Same idea with std::list ---" << std::endl;
	std::list<int> listTest;

	listTest.push_back(5);
	listTest.push_back(3);
	listTest.push_back(5);
	listTest.push_back(737);
	listTest.push_back(0);

	std::list<int>::iterator lit = listTest.begin();
	std::list<int>::iterator lite = listTest.end();

	while (lit != lite){
		std::cout << *lit << std::endl;
		++lit;
	}

	return (0);
}
