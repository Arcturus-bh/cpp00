/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:07:40 by aldalmas          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:18 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void) {
	this->oldest_idx = -1;
	colored_print(CYAN, "\n📕 Welcome to your own Phonebook ! 📕", true);
	this->run();
		
	return;
}

void	Phonebook::run(void) {
	while (1)
	{
		std::cout << "└─ Please use ADD, SEARCH or EXIT: \n►";
		std::getline(std::cin, this->user_choice);
		if (!this->user_choice.empty())
		{
			if (this->check_add() == true)
				this->add();
			else if (this->check_search() == true)
				this->search();
			else if (this->check_exit() == true)
				exit(0);
		}
	}
}

bool	Phonebook::check_add(void) const {
	if (this->user_choice.compare("add") == 0 || this->user_choice.compare("ADD") == 0)
		return true;
	return false;
}

bool	Phonebook::check_search(void) const {
	if (this->user_choice.compare("search") == 0 || this->user_choice.compare("SEARCH") == 0)
		return true;
	return false;
}

bool	Phonebook::check_exit(void) const {
	if (this->user_choice.compare("exit") == 0 || this->user_choice.compare("EXIT") == 0)
	{
		colored_print(MAGENTA, "Phonebook is now closing...", true);
		return true;
	}
	return false;
}

std::string	Phonebook::form_check_loop(const std::string& field_label) {
	std::string user_field;

	while (true)
	{
		std::cout << CYAN << "►" << field_label << ": " << RESET;
		std::getline(std::cin, user_field);
		if (user_field.empty())
			colored_print(RED, "❌ This field can't be empty", true);
		else if (char_are_spaces(user_field) == true)
			colored_print(RED, "❌ This field contains only space", true);
		else if (field_label != "Nickname" && field_label != "Phone number" && find_digit(user_field))
			colored_print(RED, "❌ This field can't contains digit", true);
		else if (field_label == "Phone number")
		{
			if (char_are_digits(user_field) == false)
		 		colored_print(RED, "❌ This field must contains only digits", true);
		 	else if (user_field.size() != 10)
		 		colored_print(RED, "❌ This field must contains 10 digits", true);
		 	else
		 		break;
		}
		else
			break;
	}
	return user_field;
}

int	Phonebook::find_slot(void) {
	for (size_t i = 0; i < 8; i++)	
	{
		if (this->contacts[i].first_name == "")
			return i;
	}
	if (this->oldest_idx == 7)
		this->oldest_idx = 0;
	else if (this->oldest_idx < 7)
		this->oldest_idx++;
	return this->oldest_idx;
}

void	Phonebook::add(void) {
	int 		idx = this->find_slot();
	std::string user_firstname = "";
	std::string user_lastname = "";
	std::string user_nickname = "";
	std::string user_phone = "";
	std::string user_secret = "";

	user_firstname = this->form_check_loop("First name");
	user_lastname = this->form_check_loop("Last name");
	user_nickname = this->form_check_loop("Nickname");
	user_phone = this->form_check_loop("Phone number");
	user_secret = this->form_check_loop("Darkest secret");
	this->contacts[idx] = Contact(user_firstname, user_lastname, user_nickname, user_phone, user_secret);	
	colored_print(GREEN, "✅👤 Contact added successfully !\n", true);
}

void	Phonebook::search(void) {
	std::string reformated_field;

	colored_print(BLUE, "╔═══════════════════════════════════════════╗", true);
	colored_print(BLUE, "║", false);
	std::cout << std::setw(10) << "Index";
	colored_print(BLUE, "║", false);
	std::cout << std::setw(10) << "First name";
	colored_print(BLUE, "║", false);
	std::cout << std::setw(10) << "Last name";
	colored_print(BLUE, "║", false);
	std::cout << std::setw(10) << "Nickname";
	colored_print(BLUE, "║", true);
	colored_print(BLUE, "║═══════════════════════════════════════════║", true);
	for (size_t i = 0; i < 8; i++) {
		colored_print(BLUE, "║", false);
		std::cout << std::setw(10) << i;
		colored_print(BLUE, "║", false);
		std::cout << std::setw(10) << check_field_len(this->contacts[i].first_name);
		colored_print(BLUE, "║", false);
		std::cout << std::setw(10) << check_field_len(this->contacts[i].last_name);
		colored_print(BLUE, "║", false);
		std::cout << std::setw(10) << check_field_len(this->contacts[i].nickname);
		colored_print(BLUE, "║", true);
	}
	colored_print(BLUE, "╚═══════════════════════════════════════════╝", true);
	this->which_contact_choose();
}

void	Phonebook::which_contact_choose(void) {
	int			idx = 0;
	std::string choice = "";

	while (true)
	{
		std::cout << "└─ Please choose an index to see more infos or use 8 for back:\n►";
		std::getline(std::cin, choice);
		if (choice < "0" || choice > "9") {
			colored_print(RED, "❌ This field must contains only digits", true);
			continue;
		}
		else
			idx = std::stoi(choice);
		if (idx >= 0 && idx <= 8)
		{
			if (idx == 8)
				return;
			if (this->contacts[idx].first_name != "")
			{
				this->show_contact_details(idx);
				return;
			}
			else
				colored_print(RED, "❌ This contact does not exist", true);
		}
		else
			colored_print(RED, "❌ You must choose between 0 and 8", true);
	}
}

std::string Phonebook::check_field_len(const std::string& field) const{
	std::string reformated = "";

	if (field.size() > 10)
	{
		reformated.append(field, 0, 10);
		reformated[9] = '.';
	}
	else
		reformated = field;
	return reformated;
}

void	Phonebook::show_contact_details(int i) const {
	colored_print(BLUE, "╔═══════════════════════════════════════════╗", true);
	colored_print(BLUE, "║", false);
	std::cout << "► First name: " << this->contacts[i].first_name << std::endl;
	colored_print(BLUE, "║", false);
	std::cout << "► Last name: " << this->contacts[i].last_name << std::endl;
	colored_print(BLUE, "║", false);
	std::cout << "► Nickname: " << this->contacts[i].nickname << std::endl;
	colored_print(BLUE, "║", false);
	std::cout << "► Phone number: " << this->contacts[i].phone_nb << std::endl;
	colored_print(BLUE, "║", false);
	std::cout << "► Dark secret: " << this->contacts[i].secret << std::endl << std::endl;
	colored_print(BLUE, "║", true);
	colored_print(BLUE, "╚═══════════════════════════════════════════╝", true);
}

Phonebook::~Phonebook(void) {
	return;
}