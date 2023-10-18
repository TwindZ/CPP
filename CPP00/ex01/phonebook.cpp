/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/18 17:55:25 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./phonebook.class.hpp"

void	f1()
{
	PhoneBook directory;
	
	std::cout << PhoneBook::get_i() << std::endl;

}

int main()
{
	
	std::cout << PhoneBook::get_i() << std::endl;
	f1();
	std::cout << PhoneBook::get_i() << std::endl;

}