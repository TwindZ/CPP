/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/19 14:20:34 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;
void	addcontact(Contact contact)
{
	std::string str;

	std::cin >> str;
	std::getline(cin, str);

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
		std::cin >> str;
		if(str.compare("ADD") == 0)
		{
			phonebook.
			addcontact(phonebook.contact[i]);
			if(i < 7)
				i++;
			else
				i = 0;
		}
		else if(str.compare("SEARCH") == 0)
		{
			
		}
		else if(str.compare("EXIT") == 0)
			break;
	}
}