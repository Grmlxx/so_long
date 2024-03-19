/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:16:21 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/19 03:45:25 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lkofitir.h>

int	animate_enemy(t_game *game)
{
	static int	frame;

	game->row = 0;
	while (game->map[game->row])
	{
		game->col = 0;
		while (game->map[game->row][game->col])
		{
			if (game->map[game->row][game->col] == 'X')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy_textures[frame].img, game->col * 64, game->row
					* 64);
				frame = (frame + 1) % 8;
			}
			game->col++;
		}
		game->col = 0;
		game->row++;
	}
	usleep(120000);
	return (1);
}
