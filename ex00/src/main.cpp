/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: paulmart <paulmart@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/09 15:17:58 by paulmart		  #+#	#+#			 */
/*   Updated: 2025/06/09 17:24:03 by paulmart		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::ifstream infile(argv[1]);
		if (!infile.is_open())
		{
			std::cerr << "Error : Could not open infile" << std::endl;
			return (1);
		}
		std::ifstream csvfile("data.csv");
		if (!csvfile.is_open())
		{
			std::cerr << "Error : Could not open CSV file" << std::endl;
			infile.close();
			return (1);
		}
		try
		{
			std::map<std::string, double> dataMap = dataMapCreation(csvfile);
			infileparsing(infile, dataMap);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		infile.close();
		csvfile.close();
		return (0);
	}
	else
	{
		std::cerr << "Error : You need to turn in a file" << std::endl;
		return (1);
	}
}