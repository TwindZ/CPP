/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/23 17:33:12 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

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
		cin >> str;
		if(str.compare("ADD") == 0)
			phonebook.addContact(i);
		else if(str.compare("SEARCH") == 0)
		{
			cout << phonebook.getContact(0).getFirstName() << endl;
			cout << phonebook.getContact(0).getName() << endl;
			cout << phonebook.getContact(0).getNickname() << endl;
			cout << phonebook.getContact(0).getPhonenumber() << endl;
			cout << phonebook.getContact(0).getDarkestsecret() << endl;
			cout << phonebook.getContact(1).getFirstName() << endl;
			cout << phonebook.getContact(1).getName() << endl;
			cout << phonebook.getContact(1).getNickname() << endl;
			cout << phonebook.getContact(1).getPhonenumber() << endl;
			cout << phonebook.getContact(1).getDarkestsecret() << endl;
		}
		else if(str.compare("EXIT") == 0)
			break;
		if(i < 7)
			i++;
		else
			i = 0;
	}
}