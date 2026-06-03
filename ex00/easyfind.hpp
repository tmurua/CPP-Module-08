/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:25:35 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/28 16:28:36 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>	// std::find

// function template to find first occurrence of value inside an int container
template <typename T>
typename T::iterator easyfind(T& container, int value){
	typename T::iterator foundIt;

	foundIt = std::find(container.begin(), container.end(), value);
	return (foundIt);
}

#endif
