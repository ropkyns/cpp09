/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:02:02 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/19 13:36:15 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <limits>
#include <climits>
#include <list>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#include <iostream>

template <typename T>
class PmergeMe
{
	private :
		clock_t		start;
		
	public :
		
};

template <typename Container>
void	algo(Container& container)
{
	if (container.size() <= 1)
		return ;

	Container	main;
	Container	pend;
	size_t i = 0;

	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		int x = container[i];
		int y = container[i + 1];
		if (x > y)
			std::swap(x, y);
		main.push_back(y);
		pend.push_back(x);
	}
	if (container.size() % 2 != 0)
		main.push_back(container.back());

	algo(main);

	int jac = findJacobsthalIndex(pend.push());
	for (int i = 2; i < jac; i++)
	{
		int	valJac = pend.at(jacobsthal(i));
		for (typename Container::iterator it = main.begin(); it != main.end(); ++it)
		{
			if (valJac < *it)
			{
				main.insert(it, valJac);
				break;
			}
		}
		if (valJac > main.back())
			main.push_back(valJac);
	}

	container = main;
}

// std::vector		Algo(std::vector container)
// {
// 	tu tarrete s'il y a qu'un seul element ou moins;

// 	std::vector	main;
// 	std::vector pend;

// 	for(tant que y'a deux elements)
// 	{
// 		grand dans main
// 		petit dans pend	
// 	}
// 	s' il y a un restant
// 		dans main;

// 	Algo(main);
// }

#endif