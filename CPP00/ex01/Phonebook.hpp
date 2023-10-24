/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:34 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook();
	~PhoneBook();
	Contact 	&getContact(int index);
	void		addContact(int index);
	std::string	setInput(std::string msg);
	void		displayList(void);
	void		displayContact(Contact &contact) const;
	void		increaseListSize();
	int			getListSize();
	std::string	searchInput();

private:

	Contact		_contact[8];
	int			_listize;

};

#endif