/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctlc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:25:02 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:30 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

int	handlle_out(char c, int f)
{
	static char	pr[5];
	static int	i;
	static int	b;

	if (f == 1)
	{
		if (i > 0)
			write(1, pr, i);
		ft_bzero(pr, sizeof(pr));
	}
	else
	{
		if (!b)
		{
			b = nb_bit(c >> 4);
			if (i > 0)
			{
				write(1, pr, i);
				ft_bzero(pr, sizeof(pr));
			}
			pr[i++] = c;
			b--;
		}
	}
	return (1);
}
