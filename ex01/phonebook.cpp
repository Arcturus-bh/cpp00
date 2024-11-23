#include "phonebook.hpp"

Phonebook::Phonebook(void) {

	this->run();

	return;
}

void	Phonebook::run(void) {
	std::cout << "📕 Welcome to your own Phonebook ! 📕" << std::endl;
	while (true)
	{
		std::cout << "[PHONEBOOK] Please use ADD, SEARCH or EXIT: \n>";
		std::cin >> this->user_choice;
		this->check_add();
		this->check_search();
		this->check_exit();
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
		std::cout << field_label << ": ";
		std::getline(std::cin, field);
		if (field_label == "Phone number" && this->check_phone_number(field))
			break ;
		if (field.empty())
			std::cout << "❌ This field can't be empty" << std::endl;
		if (all_characters_are(field, ' '))
			std::cout << "❌ This field contains only space" << std::endl;
		else 
			break ;
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

bool	Phonebook::check_phone_number(const std::string& field) {
	if (all_characters_are(field, 0))
	{
		std::cout << "❌ This field must contains only digits" << std::endl;
		return false;
	}
	else if (field.size() != 10)
	{
		std::cout << "❌ This field must contains 10 digits" << std::endl;
		return false;
	}
	return true;
}

void	Phonebook::check_search(void) const {
	if (this->user_choice.compare("search") == 0 || this->user_choice.compare("SEARCH") == 0)
		std::cout << "search found" << std::endl;
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

bool all_characters_are(const std::string& str, char c) {
	if (str.empty())
		return false;
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (std::isdigit(c) && !std::isdigit(str[i]))
			return false;
		if (std::isspace(c) && !std::isspace(str[i]))
			return false;
	}
	return true;
}