/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/24 16:05:34 by emlamoth         ###   ########.fr       */
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

Contact & PhoneBook::getContact(int index)
{
	return this->_contact[index];
}
std::string PhoneBook::setInput(std::string msg)
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
int	PhoneBook::getListSize()
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
	PhoneBook::getContact(index).setFirstName(PhoneBook::setInput("Firstname :"));
	PhoneBook::getContact(index).setName(PhoneBook::setInput("Name :"));
	PhoneBook::getContact(index).setNickname(PhoneBook::setInput("Nickname :"));
	PhoneBook::getContact(index).setPhonenumber(PhoneBook::setInput("Phone number :"));
	PhoneBook::getContact(index).setDarkestsecret(PhoneBook::setInput("Darkest secret :"));
	PhoneBook::increaseListSize();
}

void	PhoneBook::displayContact(Contact &contact) const
{
	cout << "Firstname\t: "<<contact.getFirstName() << endl;
	cout << "Name\t\t: "<<contact.getName() << endl;
	cout << "Nickname\t: "<<contact.getNickname() << endl;
	cout << "Phone number\t: "<<contact.getPhonenumber() << endl;
	cout << "Darkest secret\t: "<<contact.getDarkestsecret() << endl;
}

void	PhoneBook::displayList()
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
		for(int i = 0; i < this->getListSize(); i++)
		{
			cout << i << "|";
			if(this->getContact(i).getFirstName().length() > 10)
				cout << std::setw(10) << this->getContact(i).getFirstName().substr(0, 9) + '.' << "|";
			else
				cout << std::setw(10) << this->getContact(i).getFirstName() << "|";
			if(this->getContact(i).getName().length() > 10)
				cout << std::setw(10) << this->getContact(i).getName().substr(0, 9) + '.' << "|";
			else
				cout << std::setw(10) << this->getContact(i).getName() << "|";
			if(this->getContact(i).getNickname().length() > 10)
				cout << std::setw(10) << this->getContact(i).getNickname().substr(0, 9) + '.' << "|" << endl;
			else
				cout << std::setw(10) << this->getContact(i).getNickname() << "|" << endl;
		}
		cout << endl << "choose a contact index or type \"q\" to exit list" << endl << ">> ";
		std::getline(cin, input);
		if(!input.compare("q"))
			return ;
		else
		{
			if(input.size() > 1 || !std::isdigit((int)input[0]) || std::stoi(input) > this->_listize - 1)
				cout << "Invalid index!" << endl;
			else
			{
				valid = true;
				this->displayContact(this->getContact(std::stoi(input)));
			}	
		}
	} while (!valid);
	return ;
}