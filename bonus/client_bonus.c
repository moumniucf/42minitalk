/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:32:20 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/26 15:53:48 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handll_ack(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("done!\n");
		exit(0);
	}
}

void	send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(250);
}

void	send_null(int pid)
{
	int		i;
	char	nullc;

	nullc = '\0';
	i = 8;
	while (i--)
	{
		send_bit(pid, (nullc >> i) & 1);
	}
}

void	send_messag(int pid, char *msg)
{
	int	i;

	send_null(pid);
	while (*msg)
	{
		i = 8;
		while (i--)
		{
			send_bit(pid, (*msg >> i) & 1);
		}
		msg++;
	}
	send_null(pid);
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, &handll_ack);
	if (ac != 3)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		exit(1);
	}
	send_messag(pid, av[2]);
	return (0);
}
