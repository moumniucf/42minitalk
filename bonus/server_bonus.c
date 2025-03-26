/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:31:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/26 16:08:07 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	help_ack(siginfo_t *f)
{
	static int	e = 0;

	if (e)
	{
		kill(f->si_pid, SIGUSR1);
		e = 0;
	}
	else
		e = 1;
}

void	handlle_send(int sig, siginfo_t *f, void *c)
{
	static int	i = 0;
	static char	n = 0;

	(void)c;
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
		if (n != '\0')
		{
			write(1, &n, 1);
		}
		else
			help_ack(f);
		n = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = handlle_send;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putstr("Server pid : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
