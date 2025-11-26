/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:11:48 by naorakot          #+#    #+#             */
/*   Updated: 2025/05/15 19:13:00 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for(int i = 1; av[i] != NULL; i++)
		{
			std::string s = av[i];
			std::transform(s.begin(), s.end(), s.begin(), ::toupper);
			std::cout << s;
		}
		std::cout << '\n';
	}
	return 0;
}
