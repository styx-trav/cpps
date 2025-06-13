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

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for(char **a = &av[1]; *a != NULL; ++a)
		{
			for(char* it = *a; it != *a+strlen(*a); ++it)
				std::cout << (char)toupper(*it);
		}
		std::cout << '\n';
	}
	return 0;
}
