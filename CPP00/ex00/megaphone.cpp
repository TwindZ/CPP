/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:40:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/10/19 15:41:10 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
int main(int argc, char **argv)
{
	if(argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for(int i = 1; argv[i]; i++)
		for(int j = 0; argv[i][j]; j++)
			argv[i][j] = std::toupper(argv[i][j]);
	for(int i = 1; argv[i]; i++)
		cout << argv[i];
	cout << std::endl;
	return (0);
}