/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/25 11:09:19 by emlamoth         ###   ########.fr       */
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
	Contact &			getContact(int index);
	void				addContact();
	std::string	const 	addContactInput(std::string msg);
	void				displayList(PhoneBook &phonebook)const;
	void				displayContact(Contact &contact)const;
	void				increaseListSize();
	int					getListSize() const;
	std::string const	trimField(std::string const& str);
	int					getAddIndex()const;
	void				iterAddIndex();
	void				banner();

private:

	Contact		_contact[8];
	int			_listize;
	int			_addIndex;

};

#endif