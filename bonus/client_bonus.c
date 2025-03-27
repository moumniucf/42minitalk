/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:32:20 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/27 14:51:31 by youmoumn         ###   ########.fr       */
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

void	handll_ctlc(int sig)
{
	(void)sig;
	handlle_out('\0', 1);
	exit(0);
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
	send_nl(pid);
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, &handll_ack);
	signal(SIGINT, &handll_ctlc);
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
