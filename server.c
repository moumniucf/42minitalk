/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:11:29 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/21 14:05:00 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//PID==> processe id

void	handlle_send(int c)
{
	int i = 0;
	char n = 0;
	while(i <= 7)
	{
		n = (c << i & 1);
		write(1, &n, 1);
		i++;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int PID = getpid();
	signal(PID, handlle_send);
	printf("PID : [%d]\n", PID);
	handlle_send('a');
	// kill(PID, SIGKILL);
	pause();
	// while(1)
	// {
	// }
}
