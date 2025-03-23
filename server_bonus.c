/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 00:34:57 by tahadev           #+#    #+#             */
/*   Updated: 2025/03/23 01:12:10 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handlle_send(int sig)
{
	static int i = 0;
	static char n = 0;
    static char buff[5];
    static int b_c = 0;
	if(sig == SIGUSR1)
	{
		n = (n << 1) | 1;
	}
	else if(sig == SIGUSR2)
	{
		n = (n << 1);
	}
	i++;
    if (b_c == 0)
    {
	    if ((n & 0x80) == 0)
            b_c = 1;
	    else if ((n & 0xE0) == 0xC0)
		    b_c = 2;
	    else if ((n & 0xF0) == 0xE0)
		    b_c = 3;
	    else if ((n & 0xF8) == 0xF0)
		    b_c = 4;
    }
    buff[i / 8] = n;
	if(i / 8 + 1 == b_c)
	{
		write(1, buff, b_c);
        b_c = 0;
        i = 0;
	}
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = handlle_send;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	int PID = getpid();
	printf("PID : [%d]\n", PID);
	while(1)
		pause();
}