/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/23 17:37:21 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

using std::cout;
using std::cin;
using std::endl;
PhoneBook::PhoneBook(void) : _contact()
{	
	cout << "contructeur de Phonebook" << endl;
}

PhoneBook::~PhoneBook(void)
{
	cout << "destructeur de Phonebook" << endl;
}

Contact &PhoneBook::getContact(int index)
{
	return this->_contact[index];
}
std::string PhoneBook::setInput(std::string msg)
{
	std::string str = "";
	while(str.empty())
	{
		// cin >> str;
		cout << msg;
		std::getline(cin, str);
		cout << std::flush;
	}
	return str;
	
}

void	PhoneBook::addContact(int index)
{
	PhoneBook::getContact(index).setFirstName(PhoneBook::setInput("Firstname :"));
	PhoneBook::getContact(index).setName(PhoneBook::setInput("Name :"));
	PhoneBook::getContact(index).setNickname(PhoneBook::setInput("Nickname :"));
	PhoneBook::getContact(index).setPhonenumber(PhoneBook::setInput("Phone number :"));
	PhoneBook::getContact(index).setDarkestsecret(PhoneBook::setInput("Darkest secret :"));
}
