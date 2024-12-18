/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:13:41 by aldalmas          #+#    #+#             */
/*   Updated: 2024/12/18 15:34:55 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
	this->setFirstname("");
	this->setLastname("");
	this->setNickname("");
	this->setPhonenumber("");
	this->setSecret("");
}

Contact::Contact(std::string const first, std::string const last, std::string const nick, std::string const phone, std::string const secret) {
	this->setFirstname(first);
	this->setLastname(last);
	this->setNickname(nick);
	this->setPhonenumber(phone);
	this->setSecret(secret);
}

Contact::~Contact(void) {
	return;
}

// -------------------SETTERS---------------------------------
void Contact::setFirstname(std::string first_name) {
	this->_first_name = first_name;
}

void Contact::setLastname(std::string last_name) {
	this->_first_name = last_name;
}

void Contact::setNickname(std::string nickname) {
	this->_first_name = nickname;
}

void Contact::setPhonenumber(std::string phone) {
	this->_first_name = phone;
}

void Contact::setSecret(std::string secret) {
	this->_first_name = secret;
}

// -------------------GETTERS---------------------------------
std::string	Contact::getFirstname(void) const {
	return this->_first_name;
}

std::string	Contact::getLastname(void) const {
	return this->_last_name;
}

std::string	Contact::getNickname(void) const {
	return this->_nickname;
}

std::string	Contact::getPhonenumber(void) const {
	return this->_phone_nb;
}

std::string	Contact::getSecret(void) const {
	return this->_secret;
}