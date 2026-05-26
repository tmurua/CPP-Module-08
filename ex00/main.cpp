/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:25:44 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/26 15:25:45 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

// print container values from begin to end
template <typename ContainerType>
void	printContainer(const ContainerType &container){
	typename ContainerType::const_iterator it = container.begin();
	typename ContainerType::const_iterator ite = container.end();

	while (it != ite){
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int	main(void){
	try{
		std::vector<int> numbers;

		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);

		std::cout << "vector contents: ";
		printContainer(numbers);

		std::vector<int>::iterator found = easyfind(numbers, 30);
		std::cout << "found in vector: " << *found << std::endl;

		easyfind(numbers, 99);
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::list<int> values;

		values.push_back(5);
		values.push_back(15);
		values.push_back(25);
		values.push_back(35);

		std::cout << "list contents: ";
		printContainer(values);

		std::list<int>::iterator found = easyfind(values, 15);
		std::cout << "found in list: " << *found << std::endl;

		easyfind(values, -1);
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
