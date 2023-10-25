/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/24 20:44:06 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	(void)	argv;
	std::string str;
	PhoneBook phonebook;
	int i = 0;

	if(argc != 1)
		return (-1);
	while(42)
	{
		cout << "> ";
		std::getline(cin, str);
		if(!str.compare("ADD"))
		{
			phonebook.addContact(i);
			if(i < 7)
				i++;
			else
				i = 0;
		}	
		else if(!str.compare("SEARCH"))
			phonebook.displayList(phonebook);
		else if(!str.compare("EXIT"))
			break;
		else
		{
			cout << "Command not found !" << endl;
			cout << "Type ADD, SEARCH or EXIT" << endl;
		}
	}
}
