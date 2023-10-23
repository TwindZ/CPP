/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/23 16:20:57 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);
	Contact &getContact(int index);
	void	addContact(int index);
	std::string setInput(std::string msg);

private:

	Contact _contact[8];
	std::string	_input;

};

#endif