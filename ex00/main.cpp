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


int	main(){
    std::vector<int> vectorContainer;

    vectorContainer.push_back(10);
    vectorContainer.push_back(20);
    vectorContainer.push_back(30);

	std::cout  << "--- Success | vector container --- " << std::endl;
	std::vector<int>::iterator vectorIt = easyfind(vectorContainer, 20);
    if (vectorIt != vectorContainer.end())
        std::cout << "Found in vector: " << *vectorIt << std::endl;
    else
		std::cout << "Not found in vector" << std::endl;

	std::cout  << "--- Failure | vector container --- " << std::endl;
	vectorIt = easyfind(vectorContainer, 40);
    if (vectorIt != vectorContainer.end())
        std::cout << "Found: " << *vectorIt << std::endl;
    else
		std::cout << "Not found in vector" << std::endl;

	std::list<int> listContainer;

    listContainer.push_back(1);
    listContainer.push_back(2);
    listContainer.push_back(3);
	
	std::cout << "--- Success | list container --- " << std::endl;
    std::list<int>::iterator listIt = easyfind(listContainer, 3);
    if (listIt != listContainer.end())
        std::cout << "Found in list: " << *listIt << std::endl;
    else
		std::cout << "Not found in list" << std::endl;
	
	std::cout << "--- Failure | list container --- " << std::endl;
    listIt = easyfind(listContainer, 4);
    if (listIt != listContainer.end())
        std::cout << "Found in list: " << *listIt << std::endl;
    else
        std::cout << "Not found in list" << std::endl;
}
