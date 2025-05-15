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
		for(int i = 1; i != ac; ++i)
		{
			for(size_t j = 0; j != strlen(av[i]); ++j)
				std::cout << (char)toupper(av[i][j]);
			if (i != ac - 1)
				std::cout << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
