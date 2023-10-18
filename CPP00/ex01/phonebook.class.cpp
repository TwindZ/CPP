/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/18 17:54:48 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./phonebook.class.hpp"

int PhoneBook::_i = 0;

PhoneBook::PhoneBook(void)
{	
	PhoneBook::_i++;
}

PhoneBook::~PhoneBook(void)
{
	PhoneBook::_i--;
}

int PhoneBook::get_i(void)
{
	return(PhoneBook::_i);
}
