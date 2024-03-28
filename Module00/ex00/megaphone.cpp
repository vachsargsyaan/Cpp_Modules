/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:23:30 by vacsargs          #+#    #+#             */
/*   Updated: 2024/03/28 16:58:28 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	int	i = 0;
	int j = 0;

	if (argc == 1)
		srd::cout << * LOUD AND UNBEARABLE FEEDBACK NOISE * << '\n';
	while(argv && argv[++i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				std::cout<<(char)toupper(argv[i][j]);
			else
				std::cout<<argv[i][j];
			j++;
		}
	}
	return (0);
}
