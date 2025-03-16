/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:11:06 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/02 14:54:45 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint(unsigned long n)
{
	int		x;
	char	*s;

	x = 0;
	s = "0123456789abcdef";
	if (n >= 16)
	{
		x += ft_putpoint(n / 16);
		x += ft_putpoint(n % 16);
	}
	else
	{
		x += ft_putchar(s[n]);
	}
	return (x);
}
