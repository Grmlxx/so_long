/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:27:06 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/19 00:31:25 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	exit_game(t_game *game)
{
	free_map(game);
	free_images(game);
	free_enemy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
