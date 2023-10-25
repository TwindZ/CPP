/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/24 21:20:28 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

using std::cout;
using std::cin;
using std::endl;
PhoneBook::PhoneBook(void) : _listize(0)
{	
	cout << "contructeur de Phonebook" << endl;
}

PhoneBook::~PhoneBook(void)
{
	cout << "destructeur de Phonebook" << endl;
}

Contact & PhoneBook::getContact(int index)
{
	return this->_contact[index];
}
std::string const PhoneBook::addContactInput(std::string msg)
{
	std::string string;
	do
	{
		cout << msg;
		std::getline(cin, string);
		if (cin.fail())
			exit(-1);
		for(int i = 0; i < (int)string.length(); i++)
			if(!std::isprint(string[i]))
				string.clear();
	}while(string.empty());
	return string;
	
}
int PhoneBook::getListSize() const
{
	return this->_listize;
}

void	PhoneBook::increaseListSize()
{
	if(this->_listize < 8)
		this->_listize += 1;
}

void	PhoneBook::addContact(int index)
{
	PhoneBook::getContact(index).setFirstName(PhoneBook::addContactInput("Firstname :"));
	PhoneBook::getContact(index).setName(PhoneBook::addContactInput("Name :"));
	PhoneBook::getContact(index).setNickname(PhoneBook::addContactInput("Nickname :"));
	PhoneBook::getContact(index).setPhonenumber(PhoneBook::addContactInput("Phone number :"));
	PhoneBook::getContact(index).setDarkestsecret(PhoneBook::addContactInput("Darkest secret :"));
	PhoneBook::increaseListSize();
	cout << "--New contact succesfully added--" << endl;
}

std::string	const PhoneBook::trimField(std::string const& str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + '.';
	return str;
}

void	PhoneBook::displayContact(Contact &contact) const
{
	cout << "Firstname\t: "<<contact.getFirstName() << endl;
	cout << "Name\t\t: "<<contact.getName() << endl;
	cout << "Nickname\t: "<<contact.getNickname() << endl;
	cout << "Phone number\t: "<<contact.getPhonenumber() << endl;
	cout << "Darkest secret\t: "<<contact.getDarkestsecret() << endl;
}

void	PhoneBook::displayList(PhoneBook &phonebook)const
{
	bool valid;
	std::string input = "";
	if(this->_listize == 0)
	{
		cout << "No contact found" << endl;
		return ;
	}
	do
	{
		cout << endl;
		cout << "--------------CONTACTS-------------" << endl;
		cout << "#|Firstname |   Name   |  Nickname|" << endl;
		cout << "-----------------------------------" << endl;
		for(int i = 0; i < phonebook.getListSize(); i++)
		{
			cout << i << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getFirstName()) << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getName()) << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getNickname()) << "|" << endl;
		}
		cout << "-----------------------------------" << endl;
		cout << endl << "Choose a contact index or type \"q\" to exit listing" << endl << ">> ";
		std::getline(cin, input);
		if(!input.compare("q"))
			return ;
		else
		{
			if(input.size() > 1 || !std::isdigit((int)input[0])
				|| std::stoi(input) > this->_listize - 1)
				cout << "Invalid index!" << endl;
			else
			{
				valid = true;
				this->displayContact(phonebook.getContact(std::stoi(input)));
			}	
		}
	} while (!valid);
	return ;
}
