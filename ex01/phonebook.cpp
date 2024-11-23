/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:07:40 by aldalmas          #+#    #+#             */
/*   Updated: 2024/11/23 19:51:55 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void) {

	this->run();

	return;
}

void	Phonebook::run(void) {
	std::cout << "📕 Welcome to your own Phonebook ! 📕" << std::endl;
	while (true)
	{
		std::cout << "Please use ADD, SEARCH or EXIT: \n►";
		std::getline(std::cin, this->user_choice);
		if (!this->user_choice.empty())
		{
			this->check_add();
			this->check_search();
			this->check_exit();
		}
	}
}

void	Phonebook::check_add(void) {
	if (this->user_choice.compare("add") == 0 || this->user_choice.compare("ADD") == 0)
	{
		for (int i = 0; i < this->contacts.size(); i++)
		{
			if (this->contacts[i].first_name == "")
			{
				this->add(i);
				break ;
			}
		}
	}
}

std::string	Phonebook::form_check_loop(const std::string& field_label) {
	std::string field;

	while (true)
	{
		std::cout << "►" << field_label << ": ";
		std::getline(std::cin, field);
		if (field.empty())
			std::cout << "❌ This field can't be empty" << std::endl;
		else if (char_are_spaces(field) == true)
			std::cout << "❌ This field contains only space" << std::endl;
		if (field_label == "Phone number")
		{
			if (char_are_digits(field) == false)
				std::cout << "❌ This field must contains only digits" << std::endl;
			else if (field.size() != 10)
				std::cout << "❌ This field must contains 10 digits" << std::endl;
			else
				break;
		}
		else
			break;
	}
	std::cout << "✅ " << field_label << " confirmed" << std::endl;
	return field;
}

void	Phonebook::add(const int i) {
	std::string user_firstname = "";
	std::string user_lastname = "";
	std::string user_nickname = "";
	std::string user_phone = "";
	std::string user_secret = "";

	std::cout << "[PHONEBOOK] Adding a contact..." << std::endl;
	user_firstname = this->form_check_loop("First name");
	user_lastname = this->form_check_loop("Last name");
	user_nickname = this->form_check_loop("Nickname");
	user_phone = this->form_check_loop("Phone number");
	user_secret = this->form_check_loop("Darkest secret");
	this->contacts[i] = Contact(user_firstname, user_lastname, user_nickname, user_phone, user_secret);	
	std::cout << "✅👤 Contact added successfully !\n" << std::endl;
	this->show_contact_details(i);
}

void	Phonebook::show_contact_details(const int i) const {
	std::cout << "► First name: " << this->contacts[i].first_name << std::endl;
	std::cout << "► Last name: " << this->contacts[i].last_name << std::endl;
	std::cout << "► Nickname: " << this->contacts[i].nickname << std::endl;
	std::cout << "► Phone number: " << this->contacts[i].phone_nb << std::endl;
	std::cout << "► Dark secret: " << this->contacts[i].secret << "\n" << std::endl;
}

void	Phonebook::check_search(void) const {
	if (this->user_choice.compare("search") == 0 || this->user_choice.compare("SEARCH") == 0)
		return;
}

void	Phonebook::check_exit(void) const {
	if (this->user_choice.compare("exit") == 0 || this->user_choice.compare("EXIT") == 0)
	{
		std::cout << "Phonebook is now closing..." << std::endl;
		exit (0);
	}
}

Phonebook::~Phonebook(void) {
	//std::cout << "destructeur appelé" << std::endl;
	return;
}

bool char_are_digits(const std::string& str) {
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool char_are_spaces(const std::string& str) {
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}
