/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:34:20 by aldalmas          #+#    #+#             */
/*   Updated: 2024/11/23 19:45:27 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <array>
#include "contact.hpp"

class Phonebook 
{
	public:
		std::string 			user_choice;
		std::array<Contact, 8> 	contacts;
	
		Phonebook(void);
		~Phonebook(void);

		std::string form_check_loop(const std::string& field_label);
		void 		run(void);
		void 		show_contact_details(const int i) const;
		void 		check_add(void);
		void 		add(const int i);
		void 		check_search(void) const;
		void 		check_exit(void) const;
};

bool char_are_digits(const std::string& str);
bool char_are_spaces(const std::string& str);

#endif
