/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:35:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/11/27 13:29:19 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool char_are_digits(const std::string& str) {
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool find_digit(const std::string& str) {
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]))
			return true;
	}
	return false;
}

bool char_are_spaces(const std::string& str) {
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

void colored_print(std::string color, std::string msg, bool newline)
{
	if (newline == true)
		std::cout << color << msg << RESET << std::endl;
	else
		std::cout << color << msg << RESET;
}