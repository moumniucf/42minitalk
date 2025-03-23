/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 00:15:17 by tahadev           #+#    #+#             */
/*   Updated: 2025/03/23 01:11:42 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if(bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(500);
}

void	send_messag(int pid, char *msg)
{
	while(*msg)
	{
		int i = 8;
		while(i--)
		{
			send_bit(pid, (*msg >> i) & 1);
		}
		msg++;
	}
}

int main(int ac, char **av)
{
	if(ac != 3)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	int PID = ft_atoi(av[1]);
	if(PID <= 0)
	{
		exit(1);
	}
	send_messag(PID, av[2]);
}