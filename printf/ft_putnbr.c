/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:18:48 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/15 03:04:36 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	ft_putnbr(int n)
{
	int	len;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	len = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
