/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:07 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/17 00:46:46 by youmoumn         ###   ########.fr       */
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
void	conver_c(int n)
{
	int i = 8;
	int r;
	while(i--)
	{
		r = (n >> i & 1);
		printf("%d", r);
	}
}

void	send_messag(int pid, char *msg)
{
	int i = 7;
	while(i--)
	{
		while(msg[i++])
		{
			send_bit(pid, (msg[i] >> i & 1));
		}
	}
}

int main(int ac, char **av)
{ 
	(void)ac;
	/*if(ac < 3)
	{
		ft_putstr("Error\n");
		exit(1);
	}*/
	int PID = atoi(av[1]);
	//send_messag(PID, "youssef");
	printf("%d", PID);
	//conver_c(x);
}