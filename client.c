/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:32:10 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/29 15:42:38 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(250);
	usleep(250);
}

void	send_messag(int pid, char *msg)
{
	int	i;

	while (*msg)
	{
		i = 8;
		while (i--)
		{
			send_bit(pid, (*msg >> i) & 1);
		}
		msg++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || !is_dig(av[1]))
	{
		exit(1);
	}
	send_messag(pid, av[2]);
	return (0);
}
