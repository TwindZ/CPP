/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:16:32 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/24 14:30:50 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

Contact::Contact(void)
{
	cout << "contructeur de contact" << endl;
}
Contact::~Contact(void)
{
	cout << "destructeur de contact" << endl;
}

std::string	Contact::getFirstName(void) const
{
	return this->_first_name;
}

std::string Contact::getName(void) const
{
	return this->_name;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhonenumber(void) const
{
	return this->_phone_number;
}

std::string Contact::getDarkestsecret(void) const
{
	return this->_darkest_secret;
}

void Contact::setFirstName(std::string str)
{
	this->_first_name = str;
}
void Contact::setName(std::string str)
{
	this->_name = str;
}
void Contact::setNickname(std::string str)
{
	this->_nickname = str;
}
void Contact::setPhonenumber(std::string str)
{
	this->_phone_number = str;
}

void Contact::setDarkestsecret(std::string str)
{
	this->_darkest_secret = str;
}

