/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:52:00 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/07 14:21:20 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	ft_puthexu(unsigned long n)
{
	int		len;
	char	*symbols;

	len = 0;
	symbols = "0123456789ABCDEF";
	if (n < 16)
		return (ft_putchar(symbols[n]));
	else
	{
		len += ft_puthexu(n / 16);
		return (len + ft_puthexu(n % 16));
	}
}
