#include <iostream>
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

Contact::Contact(void)
{
	this->_first_name = "Empty";
	this->_name = "Empty";
	this->_nickname = "Empty";
	this->_phone_number = "Empty";
	this->_darkest_secret = "Empty";
}
Contact::~Contact(void)
{
	
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