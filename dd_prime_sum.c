/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dd_prime_sum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emjoao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:28:56 by emjoao            #+#    #+#             */
/*   Updated: 2025/09/26 13:32:00 by emjoao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int is_prim(int n)
{
	int i;
	if (n < 2)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int ft_atoi(char *s)
{
	int i;
	i = 0;
	int sign = 1;
	int res = 0;

	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+'){
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int main(int ac, char *av[])
{
	int i;
	int n;
	(void)av;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);

		while (n > 0)
		{
			if (is_prim(n))
				i += n;
			n--;

		}
		printf("%d", i);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return 0;
}
