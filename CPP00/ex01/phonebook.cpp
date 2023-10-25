/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/25 16:02:44 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

using std::cout;
using std::cin;
using std::endl;
PhoneBook::PhoneBook(void) : _listize(0), _addIndex(0)
{
	
}

PhoneBook::~PhoneBook(void)
{
	
}

void	PhoneBook::banner()
{
	cout << "--------------------------------------------" << endl;
	cout << "|           PHONEBOOK by emlamoth          |" << endl;
	cout << "--------------------------------------------" << endl;
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

void	PhoneBook::addContact()
{
	this->getContact(this->getAddIndex()).setFirstName(this->addContactInput("Firstname :"));
	this->getContact(this->getAddIndex()).setName(this->addContactInput("Name :"));
	this->getContact(this->getAddIndex()).setNickname(this->addContactInput("Nickname :"));
	this->getContact(this->getAddIndex()).setPhonenumber(this->addContactInput("Phone number :"));
	this->getContact(this->getAddIndex()).setDarkestsecret(this->addContactInput("Darkest secret :"));
	this->increaseListSize();
	this->iterAddIndex();
	cout << "-------New contact succesfully added--------" << endl;
}

std::string	const PhoneBook::trimField(std::string const& str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + '.';
	return str;
}

void	PhoneBook::displayContact(Contact &contact) const
{
	cout << endl;
	cout << "Firstname\t: "<<contact.getFirstName() << endl;
	cout << "Name\t\t: "<<contact.getName() << endl;
	cout << "Nickname\t: "<<contact.getNickname() << endl;
	cout << "Phone number\t: "<<contact.getPhonenumber() << endl;
	cout << "Darkest secret\t: "<<contact.getDarkestsecret() << endl << endl;
}

int	PhoneBook::getAddIndex()const
{
	return this->_addIndex;
}


void	PhoneBook::iterAddIndex()
{
	if(this->_addIndex < 7)
		this->_addIndex++;
	else
		this->_addIndex = 0;
}

void	PhoneBook::displayList(PhoneBook &phonebook)const
{
	bool valid;
	std::string input = "";
	if(phonebook._listize == 0)
	{
		cout << "--------------No contact found--------------" << endl;
		return ;
	}
	do
	{
		cout << endl;
		cout << "-------------------CONTACTS-----------------" << endl;
		cout << "  Index # |Firstname |   Name   |Nickname  |" << endl;
		cout << "--------------------------------------------" << endl;
		for(int i = 0; i < phonebook.getListSize(); i++)
		{
			cout << std::setw(10) << i + 1 << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getFirstName()) << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getName()) << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getNickname()) << "|" << endl;
		}
		cout << "--------------------------------------------" << endl;
		cout << endl << "Choose a contact index or type \"q\" to exit listing" << endl << ">> ";
		std::getline(cin, input);
		if(!input.compare("q"))
			return ;
		else if (cin.fail())
			exit(-1);
		else
		{
			if(input.size() > 1 || !std::isdigit((int)input[0])
				|| std::atoi(input.c_str()) > phonebook._listize || std::atoi(input.c_str()) < 1)
				cout << "Invalid index!" << endl;
			else
			{
				valid = true;
				phonebook.displayContact(phonebook.getContact(std::atoi(input.c_str()) - 1));
			}	
		}
	} while (!valid);
	return ;
}
