/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:07:27 by youmoumn          #+#    #+#             */
/*   Updated: 2024/11/30 15:11:17 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int		i;
	char	*uper;
	char	*lower;

	i = 0;
	lower = "0123456789abcdef";
	uper = "0123456789ABCDEF";
	if (n < 16 && c == 'x')
		i += ft_putchar(lower[n]);
	else if (n < 16 && c == 'X')
		i += ft_putchar(uper[n]);
	else
	{
		i += ft_puthex(n / 16, c);
		i += ft_puthex(n % 16, c);
	}
	return (i);
}
