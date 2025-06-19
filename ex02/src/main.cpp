/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:01:46 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/19 15:32:38 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

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

int	main(int argc, char **argv)
{
	if (argc < 3)
		std::cerr << "Error : not enough argument" << std::endl;
	else
	{
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
		V.ford();
		D.ford();
		printContainer(V.getContainer(), "vec");
		printContainer(D.getContainer(), "deq");
	}
}