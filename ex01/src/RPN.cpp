/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:50:41 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/12 16:40:19 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

Rpn::Rpn(){}

Rpn::Rpn(const Rpn &R)
{
	*this = R;
}

Rpn &Rpn::operator= (const Rpn &R)
{
	if (this == &R)
		return (*this);
	return (*this);
}

Rpn::~Rpn(){}

void	Rpn::readInput(std::string &input)
{
	std::string ope = "+-/*";
	for (size_t i = 0; i < input.length(); i++)
	{
		if(isdigit(input[i]))
		{
			this->_pile.push((input[i] - '0'));
		}
		else if (ope.find(input[i]) != std::string::npos)
		{
			 if (_pile.size() < 2)
				throw std::invalid_argument("Error : not enough operands");
			double num2 = _pile.top(); _pile.pop();
			double num1 = _pile.top(); _pile.pop();
			double result = calculFunction(input[i], num1, num2);
			_pile.push(result);
		}
		else if (isspace(input[i]))
			continue;
		else
			throw std::invalid_argument("Error : invalid input");
	}
	if (_pile.size() != 1)
		throw std::invalid_argument("Error : invalid RPN expression");
	std::cout << _pile.top() << std::endl;
}

double	Rpn::calculFunction(char op, double num1, double num2)
{
	switch (op)
	{
	case '+':
		return (num1 + num2);
	case '-':
		return (num1 - num2);
	case '*':
		return (num1 * num2);
	case '/':
		if (num2 == 0)
			throw std::invalid_argument("Error : can't divide by zero");
		return (num1 / num2);
	}
	return (0);
}