#include "contact.hpp"

Contact::Contact(
	std::string const first,
	std::string const last,
	std::string const nick,
	std::string const phone,
	std::string const secret) :
	first_name(first),
	last_name(last),
	nickname(nick),
	phone_nb(phone),
	secret(secret)
{
	//std::cout << "Contact constructeur appelé" << std::endl;
	return;
}

Contact::~Contact(void) {
	//std::cout << "Contact constructeur appelé" << std::endl;
	return;
}