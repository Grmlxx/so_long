/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:16:21 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/22 16:22:46 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lkofitir.h>

int	find_enemy(t_game *game)
{
	game->row = 0;
	while (game->map[game->row])
	{
		game->col = 0;
		while (game->map[game->row][game->col])
		{
			if (game->map[game->row][game->col] == 'X')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy_textures[game->frame].img, game->col * 64,
					game->row * 64);
			}
			game->col++;
		}
		game->col = 0;
		game->row++;
	}
	usleep(95000);
	return (0);
}

int	animate_enemy(t_game *game)
{
	find_enemy(game);
	game->frame++;
	if (game->frame == 8)
		game->frame = 0;
	return (0);
}
