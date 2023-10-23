#include <iostream>
#include <string.h>
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

Contact::Contact(void)
{
	cout << "contructeur de contact" << endl;
	this->_first_name = "Empty";
	this->_name = "Empty";
	this->_nickname = "Empty";
	this->_phone_number = "Empty";
	this->_darkest_secret = "Empty";
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

bool Contact::setFirstName(std::string str)
{
	this->_first_name = str;
	return true;
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

