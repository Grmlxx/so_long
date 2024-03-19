/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:08:12 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/15 03:04:26 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	ft_putformat(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr((va_arg(args, int)));
	else if (specifier == 'x')
		count += ft_puthexl((unsigned long)(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		count += ft_puthexu((unsigned long)(va_arg(args, unsigned int)));
	else if (specifier == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'p')
		count += ft_putpointer((va_arg(args, void *)));
	else
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_putformat(*++format, args);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
