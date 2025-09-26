/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emjoao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:23:35 by emjoao            #+#    #+#             */
/*   Updated: 2025/09/26 19:16:55 by emjoao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int t;
	int last, end;
	int j;
	int l;

	if (ac > 1)
	{
		t = 1;
	//	i = 0;
		while (t < ac)
		{
			i = 0;
			while (av[t][i] == ' ' || av[t][i] == '\t')
			{
				write(1, &av[t][i], 1);
				i++;
			}
			while (av[t][i])
			{
				j = i;
				while (av[t][j] && av[t][j] != ' ' && av[t][j] != '\t')
					j++;
				last = i;
				while (i < j)
				{
					if (av[t][i] >= 'A' && av[t][i] <= 'Z')
						av[t][i] += 32;
					if (i == last && (av[t][i] >= 'a' && av[t][i] <= 'z'))
						av[t][i] -= 32;
					write(1, &av[t][i], 1);
					i++;
				}
				if(av[t][i] == ' ' || av[t][i] == '\t'){
					write(1, &av[t][i], 1);
					i++;
				}
		//		i++;
			}
			write(1, "\n", 1);
			t++;
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}
