/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:01:43 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/18 17:34:58 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int a = 0;
	int b = 1;
	int result = 0;
	for (int i = 2; i <= n; ++i)
	{
		result = b + 2 * a;
		a = b;
		b = result;
	}
	return result;
}

int findJacobsthalIndex(int size)
{
	int k = 0;
	while (jacobsthal(k) <= size)
		++k;
	return (k - 1);
}