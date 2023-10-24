/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/24 17:27:58 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

using std::cin;
using std::cout;
using std::endl;

void fillContact(PhoneBook &phonebook)
{
	for(int i = 0; i < 8; i++)
	{
		phonebook.getContact(i).setFirstName("Bob");
		phonebook.getContact(i).setName("Binnette");
		phonebook.getContact(i).setNickname("Bob the builder");
		phonebook.getContact(i).setPhonenumber("911");
		phonebook.getContact(i).setDarkestsecret("True name Barbara");
	}
}

int main(int argc, char **argv)
{
	(void)	argv;
	std::string str;
	PhoneBook phonebook;
	int i(0);

	if(argc != 1)
		return (-1);
	while(42)
	{
		cout << "> ";
		std::getline(cin, str);
		if(str.compare("ADD") == 0)
		{
			phonebook.addContact(i);
			if(i < 7)
				i++;
			else
				i = 0;
		}	
		else if(str.compare("SEARCH") == 0)
			phonebook.displayList(phonebook);
		else if(str.compare("EXIT") == 0)
			break;
		else
		{
			cout << "No command found !" << endl;
			cout << "Type ADD, SEARCH or EXIT" << endl;

		}
	}
}