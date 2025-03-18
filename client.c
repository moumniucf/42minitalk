/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:07 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/17 12:51:26 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	send_bit(int pid, int bit)
{
	if(bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}
void	conver_c(char n)
{
	int i = 8;
	int r;
	while(i--)
	{
		r = (n >> i & 1);
	}
}

void	send_messag(int pid, char *msg)
{
	while(*msg)
	{
		int i = 7;
		while(i >= 0)
		{
			send_bit(pid, (msg[i] >> i & 1));
			i--;
		}
		msg++;
	}
}

int main(int ac, char **av)
{
	int PID = ft_atoi(av[1]);
	if(ac == 3)
	{
		conver_c(PID);
		send_messag(PID, av[2]);
	}
	else
	{
		ft_putstr("Error\n");
		exit(1);
	}
}