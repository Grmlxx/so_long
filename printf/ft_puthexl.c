/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:52:08 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/07 14:22:57 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	ft_puthexl(unsigned long n)
{
	int		len;
	char	*symbols;

	len = 0;
	symbols = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar(symbols[n]));
	else
	{
		len += ft_puthexl(n / 16);
		return (len + ft_puthexl(n % 16));
	}
}
