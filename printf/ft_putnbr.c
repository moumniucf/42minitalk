/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:46:52 by youmoumn          #+#    #+#             */
/*   Updated: 2024/11/27 16:57:57 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		x;
	long	y;

	x = 0;
	y = (long)n;
	if (y < 0)
	{
		x += ft_putchar('-');
		y *= -1;
	}
	if (y > 9)
	{
		x += ft_putnbr(y / 10);
		x += ft_putnbr(y % 10);
	}
	else
	{
		x += ft_putchar(y + 48);
	}
	return (x);
}
