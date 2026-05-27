/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:33:07 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/28 01:10:43 by tmurua           ###   ########.fr       */
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

// shortest span = smallest difference between 2 stored numbers
int Span::shortestSpan() const{
	if (_numbers.size() < 2)
		throw std::runtime_error("Error: not enough numbers to find a span");

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = sortedNumbers[1] - sortedNumbers[0];

	for (std::size_t i = 1; i < sortedNumbers.size() - 1; i++){
		int currentSpan = sortedNumbers[i + 1] - sortedNumbers[i];
		if (currentSpan < shortest)
			shortest = currentSpan;
	}
	return (shortest);
}

// longest span = biggest difference between smallest and biggest number
int Span::longestSpan() const{
	if (_numbers.size() < 2)
		throw std::runtime_error("Error: not enough numbers to find a span");

	int smallest = *std::min_element(_numbers.begin(), _numbers.end());
	int biggest = *std::max_element(_numbers.begin(), _numbers.end());

	return (biggest - smallest);
}
