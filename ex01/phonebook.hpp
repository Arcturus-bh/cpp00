/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:34:20 by aldalmas          #+#    #+#             */
/*   Updated: 2024/11/27 16:55:08 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>
#include <cctype>
#include <array>
#include <algorithm>
#include "contact.hpp"
#include <iomanip>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

class Phonebook 
{
	public:
		int						oldest_idx;
		std::string 			user_choice;
		std::array<Contact, 8> 	contacts;

		Phonebook(void);
		~Phonebook(void);

		std::string form_check_loop(const std::string& field_label);
		std::string check_field_len(const std::string& field) const;
		int			find_slot(void);
		bool 		check_add(void) const;
		bool		check_search(void) const;
		bool 		check_exit(void) const;
		void 		add(void);
		void 		run(void);
		void 		show_contact_details(int i) const;
		void		which_contact_choose(void);
		void		search(void);
};

bool char_are_digits(const std::string& str);
bool char_are_spaces(const std::string& str);
bool find_digit(const std::string& str);
void colored_print(std::string color, std::string msg, bool newline);

#endif