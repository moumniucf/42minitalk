/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:11:29 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/20 23:48:43 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//PID==> processe id

void	handlle_send(char c)
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
	//int PID = getpid();
	//printf("PID : [%d]\n", PID);
	handlle_send('a');
	// kill(PID, SIGKILL);
	/*while(1)
	{
		pause();
	}*/
}
