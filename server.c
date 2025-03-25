/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:11:29 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/25 13:57:09 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handlle_send(int sig)
{
	static int	i = 0;
	static char	n = 0;

	if (sig == SIGUSR1)
	{
		n = (n << 1) | 1;
	}
	else if (sig == SIGUSR2)
	{
		n = (n << 1);
	}
	i++;
	if (i == 8)
	{
		write(1, &n, 1);
		n = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = handlle_send;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putstr("Server pid : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
}
