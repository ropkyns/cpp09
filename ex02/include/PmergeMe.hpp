/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:02:02 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/23 11:27:22 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
#include <cerrno>

template <typename T>
class PmergeMe
{
	private :
		double	_elapsed;
		T		_container;

	public :
		PmergeMe();
		~PmergeMe();
		
		void	add(int value);
		T		&getContainer();
		double	getElapsed();
		void	ford();
};

int		jacobsthal(int n);
int		findJacobsthalIndex(int size);

template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
void	PmergeMe<T>::add(int value)
{
	_container.push_back(value);
}
template <typename T>
T &PmergeMe<T>::getContainer()
{
	return (_container);
}
template <typename T>
double	PmergeMe<T>::getElapsed()
{
	return (_elapsed);
}

template <typename Container>
void	algo(Container &container)
{
	if (container.size() <= 1)
		return ;

	Container	main;
	Container	pend;

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

	int jac = findJacobsthalIndex(pend.size());
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

	for (size_t i = 0; i < pend.size(); ++i)
	{
		int val = pend[i];

		bool exists = false;
		for (typename Container::iterator it = main.begin(); it != main.end(); ++it)
		{
				if (*it == val)
			{
				exists = true;
				break;
			}
		}
		if (exists)
			continue;

		typename Container::iterator it = main.begin();
		for (; it != main.end(); ++it)
		{
			if (val < *it)
				break;
		}
		main.insert(it, val);
	}
	container = main;
}

template <typename T>
void	PmergeMe<T>::ford()
{
	clock_t _start = std::clock();
	algo(_container);
	clock_t _end = std::clock();
	_elapsed = static_cast<double>(_end - _start) / CLOCKS_PER_SEC;
}

// void		Algo(std::vector container)
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