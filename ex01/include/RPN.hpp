/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:50:08 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/12 16:16:39 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <fstream>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cerrno>
# include <cctype>
# include <stack>

class Rpn
{
	private :
		std::stack<double>	_pile;
	public :
		Rpn();
		Rpn(const Rpn &R);
		~Rpn();
		Rpn &operator= (const Rpn &R);

		void	readInput(std::string &input);
		double	calculFunction(char op, double num1, double num2);
};

#endif