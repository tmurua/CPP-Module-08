/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:12:04 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/30 01:12:48 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <vector>

int	main(void){
	try{
		std::cout << "--- Subject test ---" << std::endl;

		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "--- Fill with range of iterators test ---" << std::endl;

		Span sp(8);
		std::vector<int> values;

		values.push_back(100);
		values.push_back(101);
		values.push_back(150);
		values.push_back(100);
		values.push_back(200);

		sp.addNumbers(values.begin(), values.end());
		
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "--- Span already full error test ---" << std::endl;

		Span sp(2);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "--- Not enough numbers error test ---" << std::endl;

		Span sp(5);

		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "--- 10,000 numbers test ---" << std::endl;

		Span sp(10000);

		for (int i = 0; i < 10000; i++)
			sp.addNumber(i);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	try{
		std::cout << "--- 100,000 numbers test ---" << std::endl;

		Span sp(100000);

		for (int i = 0; i < 100000; i++)
			sp.addNumber(i);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

}
