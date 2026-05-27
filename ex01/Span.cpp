/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:33:07 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/27 17:36:17 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>	// std::sort, std::min_element, std::max_element

Span::Span() : _maxSize(0){}

Span::Span(unsigned int maxSize) : _maxSize(maxSize){}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers){}

Span &Span::operator=(const Span &other){
	if (this != &other){
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(){}

// add one number if there is still space
void Span::addNumber(int number){
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Error: Span is already full");
	_numbers.push_back(number);
}
