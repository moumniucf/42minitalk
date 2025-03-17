/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:59:35 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/16 23:42:01 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i = 0;
	while(s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);
}

int		ft_atoi(char *s)
{
	int i;
	int x = 1;
	int res = 0;
	while(s[i] == ' ' || s[i] == '\t')
		i++;
	if(s[i] == '+' || s[i] == '-')
	{
		if(s[i] == '-')
			x *=- 1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (res * x);
}