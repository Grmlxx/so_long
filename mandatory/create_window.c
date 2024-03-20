/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:27:09 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/20 00:13:46 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	create_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		bye_bye("Error initializing MiniLibX", game);
	game->win = mlx_new_window(game->mlx, game->win_width * 64, game->win_height
			* 64, "so_long Game");
	if (!game->win)
		bye_bye("Error creating window", game);
}
