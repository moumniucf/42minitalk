/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:57:18 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/28 14:51:57 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
	usleep(100);
}

int	is_dig(char *pid)
{
	while (*pid)
	{
		if (*pid < '0' || *pid > '9')
			return (0);
		pid++;
	}
	return (1);
}

int	nb_bit(int n)
{
	if (n == 12)
		return (2);
	else if (n == 14)
		return (3);
	else if (n == 15)
		return (4);
	return (1);
}
