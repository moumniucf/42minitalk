/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:11:29 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/16 16:09:44 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//PID==> processe id
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int PID = getpid();
	printf("PID : [%d]\n", PID);
	// kill(PID, SIGKILL);
	while(1)
	{
		pause();
	}
}