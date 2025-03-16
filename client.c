/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:07 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/16 15:08:36 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//PID==> processe id
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("[%d]\n", getpid());
	while(1337)
		pause();
}