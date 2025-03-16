/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:30:16 by youmoumn          #+#    #+#             */
/*   Updated: 2024/11/28 14:56:56 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	x;

	x = 0;
	if (n > 9)
	{
		x += ft_putunsigned(n / 10);
		x += ft_putunsigned(n % 10);
	}
	else
	{
		x += ft_putchar(n + 48);
	}
	return (x);
}
