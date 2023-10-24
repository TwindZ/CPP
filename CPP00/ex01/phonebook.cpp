/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/24 17:24:39 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
std::string PhoneBook::addContactInput(std::string msg)
{
	std::string str = "";
	do
	{
		cout << msg;
		std::getline(cin, str);
		if (cin.fail())
			exit(-1);
		for(int i = 0; i < (int)str.length(); i++)
			if(!std::isprint(str[i]))
				str.clear();
	}while(str.empty());
	return str;
	
}
int	PhoneBook::getListSize() const
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
		for(int i = 0; i < phonebook.getListSize(); i++)
		{
			cout << i << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getFirstName()) << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getName()) << "|";
			cout << std::setw(10) << phonebook.trimField(phonebook.getContact(i).getNickname()) << "|" << endl;
		}
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
