#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact 
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_nb;
		std::string secret;

		Contact() : first_name(""), last_name(""), nickname(""), phone_nb(""), secret("") {

		}
		Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		~Contact(void);
};

#endif