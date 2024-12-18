/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:13:35 by aldalmas          #+#    #+#             */
/*   Updated: 2024/12/18 15:28:45 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact 
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_nb;
		std::string _secret;

	public:
		Contact();
		Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		~Contact(void);
	
		void		setFirstname(std::string first_name);
		void		setLastname(std::string last_name);
		void		setNickname(std::string nickname);
		void		setPhonenumber(std::string phone);
		void		setSecret(std::string secret);

		std::string	getFirstname(void) const;
		std::string	getLastname(void) const;
		std::string	getNickname(void) const;
		std::string	getPhonenumber(void) const;
		std::string	getSecret(void) const;
};

#endif