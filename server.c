/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:11:29 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/22 00:31:41 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//PID==> processe id

void	handlle_send(int sig)
{
	static int i = 0;
	static char n = 0;
	if(sig == SIGUSR1)
	{
		n = (n << 1) | 1;
	}
	else if(sig == SIGUSR2)
	{
		n = (n << 1);
	}
	i++;
	if(i == 8)
	{
		write(1, &n, 1);
		n = 0;
		i = 0;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	struct sigaction sa;
	sa.sa_handler = handlle_send;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	int PID = getpid();
	printf("PID : [%d]\n", PID);
	while(1)
		pause();
}

	/*int tab[] = {SIGUSR2, SIGUSR1, SIGUSR1, SIGUSR1, SIGUSR2, SIGUSR2, SIGUSR2, SIGUSR1};
	int i = 0;
	while(i < 8)
	{
		handlle_send(tab[i]);
		i++;
	}*/