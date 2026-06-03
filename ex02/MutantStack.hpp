/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:02:04 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/29 01:12:48 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// MutantStack acts like std::stack, but can also iterate from begin() to end() 
template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// std::stack stores its elements in an internal container, std::deque<T> by default
	// std::stack provides the name container_type for this internal container type
	// std::stack<T>::container_type::iterator is the iterator type of this internal container
	typedef typename std::stack<T>::container_type::iterator iterator;

	// default constructor just calls the std::stack constructor
	MutantStack() : std::stack<T>(){}

	// copy constructor copies only the std::stack part from other MutantStack
	MutantStack(const MutantStack &other) : std::stack<T>(other){}

	// assigns only the std::stack part from another MutantStack
	MutantStack &operator=(const MutantStack &other){
		if (this != &other)
			std::stack<T>::operator=(other);
		return (*this);
	}

	~MutantStack(){}

	//"c" is the internal container where std::stack stores its elements
	iterator begin(){
		return (this->c.begin());
	}

	iterator end(){
		return (this->c.end());
	}
};

#endif
