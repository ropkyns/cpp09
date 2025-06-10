/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:17:45 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/10 17:00:52 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"


std::map<std::string, double> dataMapCreation(std::ifstream &csvfile)
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
				throw std::runtime_error("Error :\nInvalid value in CSV file");
			dataMap[key] = value;
		}
	}
	return(dataMap);
}

void infileparsing (std::ifstream &infile, std::map<std::string, double> &dataMap)
{
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string key, valueStr;
		std::string::size_type sep = line.find('|');
		if (sep != std::string::npos)
		{
			std::string key = line.substr(0, sep);
			std::string valueStr = line.substr(sep + 1);
			char *endptr;
			errno = 0;
			double value = std::strtod(valueStr.c_str(), &endptr);
			if (endptr == valueStr.c_str() || errno == ERANGE)
				throw std::runtime_error("Error :\nInvalid read in infile");
			if (!checkdate(key))
			{
				std::cerr << "Error : bad input => " << key << std::endl; 
				continue;
			}
			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cerr << "Error : too large a number." << std::endl;
				continue;
			}
			double result = getResult(key, value, dataMap);
			// std::cout << key << " => " << value << " = " << result
		}
	}
}

double	getResult(std::string date, double value, std::map<std::string, double> &dataMap)
{
	std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator it = dataMap.upper_bound(date);
	if (it != dataMap.end())
		return (it->second * value);
	else
		return (dataMap.begin()->second * value);
}

bool	checkdate(std::string &date)
{
	int		year;
	int		month;
	int		day;
	char	dash;
	char	dash2;
	std::istringstream	ifs(date);
	int		day_by_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (!ifs >> year >> dash >> month >> dash2 >> day)
		return (false);
	if (year < 0 || year > 2025)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > day_by_month[month - 1])
		return (false);
	return (true);
}