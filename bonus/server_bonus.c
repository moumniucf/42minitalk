/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:31:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/28 13:38:11 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	help_send(char n, siginfo_t *f)
{
	static int	i = 0;
	static char	ptr[5];
	static int	b = 0;

	ptr[i++] = n;
	if (i == 1)
		b = nb_bit(n >> 4);
	if (--b == 0)
	{
		write(1, ptr, i);
		i = 0;
	}
	if (n == '\n')
		kill(f->si_pid, SIGUSR1);
}

void	handlle_send(int sig, siginfo_t *f, void *c)
{
	static int	i = 0;
	static char	n = 0;
	static int	pid = 0;

	(void)c;
	if (pid != f->si_pid)
	{
		pid = f->si_pid;
		n = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		n = (n << 1) | 1;
	else if (sig == SIGUSR2)
		n = (n << 1);
	i++;
	if (i == 8)
	{
		help_send(n, f);
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
