/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:01:46 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/24 15:34:59 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <set>

bool isPositiveNumber(const char* str)
{
	char* endptr;
	errno = 0;
	long val = std::strtol(str, &endptr, 10);
	if (*str == '\0' || *endptr != '\0' || errno == ERANGE)
		return false;
	if (val > INT_MAX || val <= 0)
		return false;
	return true;
}

bool hasDuplicates(int argc, char **argv)
{
	std::set<std::string> seen;
	for (int i = 1; i < argc; ++i)
	{
		std::string val(argv[i]);
		if (seen.find(val) != seen.end())
			return (true);
		seen.insert(val);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		std::cerr << "Error : not enough argument" << std::endl;
	else
	{
		if (hasDuplicates(argc, argv))
		{
			std::cerr << "Error: duplicate arguments are not allowed" << std::endl;
			return (1);
		}
		PmergeMe<std::vector<int> > V;
		PmergeMe<std::deque<int> > D;
		for (int i = 1; i < argc; i++)
		{
			if (!isPositiveNumber(argv[i]))
			{
				std::cerr << "Error : you need to turn in only positive number" << std::endl;
				return (1);
			}
			V.add(std::atoi(argv[i]));
			D.add(std::atoi(argv[i]));
		}

		std::cout << "Before: ";
		for (std::vector<int>::const_iterator it = V.getContainer().begin(); it != V.getContainer().end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		V.ford();

		std::cout << "After: ";
		for (std::vector<int>::const_iterator it = V.getContainer().begin(); it != V.getContainer().end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Time to process a range of " << V.getContainer().size() << " elements with std::vector : " << V.getElapsed() << " us" << std::endl;

		D.ford();

		std::cout << "Time to process a range of " << D.getContainer().size() << " elements with std::deque : " << D.getElapsed() << " us" << std::endl;
	}
}