/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:17:34 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/10 16:33:43 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <cerrno>

std::map<std::string, double>	dataMapCreation(std::ifstream &csvfile);
void							infileparsing (std::ifstream &infile, std::map<std::string, double> &dataMap);
bool							checkdate(std::string &date);
double							getResult(std::string date, double value, std::map<std::string, double> &dataMap);

#endif