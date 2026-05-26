/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:25:35 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/26 15:25:36 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>	// std::find
#include <stdexcept>	// std::runtime_error

// template function to find first occurrence of targetValue inside a container
// assumes container stores ints and supports begin() / end()
template <typename T>
typename T::iterator	easyfind(T &container, int targetValue){
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), targetValue);
	if (it == container.end())
		throw std::runtime_error("Error: value not found in container");
	return (it);
}

// const overload so easyfind also works with const containers
template <typename T>
typename T::const_iterator	easyfind(const T &container, int targetValue){
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), targetValue);
	if (it == container.end())
		throw std::runtime_error("Error: value not found in container");
	return (it);
}

#endif
