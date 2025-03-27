/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:02:17 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:05 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	ft_atoi(char *s)
{
	int	i;
	int	x;
	int	res;

	if (!s)
		return (0);
	res = 0;
	x = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (res * x);
}

void	ft_putnbr(int n)
{
	long	x;

	x = (long)n;
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + 48);
}

void	send_nl(int pid)
{
	int		i;
	char	nl;

	nl = '\n';
	i = 8;
	while (i--)
	{
		send_bit(pid, (nl >> i) & 1);
	}
}
