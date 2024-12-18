/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:25:33 by aldalmas          #+#    #+#             */
/*   Updated: 2024/12/18 14:40:48 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << RED << "ERROR: no argument allowed" << RESET << std::endl;
		return 1;
	}
	Phonebook phonebook;
	return 0;
}