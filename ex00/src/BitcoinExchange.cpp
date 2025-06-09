/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:17:45 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/09 17:51:33 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"


std::map<std::string, double> dataMapCreation(std::ifstream csvfile)
{
	std::map<std::string, double> dataMap;
	std::string line;
	std::getline(csvfile, line);
	while (std::getline(csvfile, line))
	{
		std::istringstream iss(line);
		std::string key, valueStr;
		if (std::getline(iss, key, ',') && std::getline(iss, valueStr))
		{
			char *endptr;
			errno = 0;
			double value = std::strtod(valueStr.c_str(), &endptr);
			if (endptr == valueStr.c_str() || errno == ERANGE)
			{
				throw std::runtime_error("Error :\nInvalid value in CSV file");
			}
			dataMap[key] = value;
		}
	}
	return(dataMap);
}
