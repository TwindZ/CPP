/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/18 17:46:07 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class Contact
{
public:

private:

};

class PhoneBook
{
public:
	
	Contact contact[8];
	
	PhoneBook(void);
	~PhoneBook(void);
	static int get_i(void);
	
private:
	
	static int _i;
};

#endif