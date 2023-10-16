/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:40:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/16 17:33:25 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char to_upper(char c)
{
	if (c >= 'a' || c <= 'z')
		c -= 32;
	return (c);
}
namespace test
{
	int test1 = 2;
	int test2 = 5;
	int f(void) {return 8; };
}

namespace salut = test;

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char buffer[200];
	
	std::cout << "salut" << std::endl;
	printf("%d %d %d\n", test::test1, test::test2, salut::f());
	std::cin >> buffer;
	for(int i = 0; buffer[i]; i++)
		buffer[i] = to_upper(buffer[i]);
	std::cout << "vous avez ecrit : " << buffer << std::endl;
	return (0);
}