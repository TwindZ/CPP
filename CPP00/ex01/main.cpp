/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/25 11:09:41 by emlamoth         ###   ########.fr       */
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

	if(argc != 1)
		return (-1);
	phonebook.banner();
	while(42)
	{
		cout << "---------Type ADD, SEARCH or EXIT-----------" << endl;
		cout << "> ";
		std::getline(cin, str);
		if(!str.compare("ADD"))
			phonebook.addContact();
		else if(!str.compare("SEARCH"))
			phonebook.displayList(phonebook);
		else if(!str.compare("EXIT"))
			break;
		else if (cin.fail())
			exit(-1);
		else
			cout << "Command not found !" << endl;
	}
}
