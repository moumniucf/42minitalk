/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:10:54 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/02 18:40:20 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printother(va_list lst, const char c)
{
	int	ptr;

	ptr = 0;
	if (c == '%')
		ptr += ft_putchar('%');
	else if (c == 'p')
		ptr += ft_putstr("0x") + ft_putpoint(va_arg(lst, unsigned long));
	else if (c == 'u')
		ptr += ft_putunsigned(va_arg(lst, unsigned int));
	else if (c == 'c')
		ptr += ft_putchar(va_arg(lst, int));
	else if (c == 'd' || c == 'i')
		ptr += ft_putnbr(va_arg(lst, int));
	return (ptr);
}

int	ft_printf(const char *form, ...)
{
	int			x;
	va_list		lst;

	va_start (lst, form);
	x = 0;
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (*form == '\0')
				break ;
			if (*form == 's')
				x += ft_putstr(va_arg(lst, char *));
			else if (*form == 'x' || *form == 'X')
				x += ft_puthex(va_arg(lst, int), *form);
			else
				x += ft_printother(lst, *form);
		}
		else
			x += ft_putchar(*form);
		form++;
	}
	return (x);
}
