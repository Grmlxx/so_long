/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:00:30 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/15 03:04:39 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	ft_putpointer(void *p)
{
	int	len;

	len = 0;
	if (p == NULL)
		return (ft_putstr("0x0"));
	else
	{
		len += ft_putstr("0x");
		len += ft_puthexl((unsigned long)p);
	}
	return (len);
}
