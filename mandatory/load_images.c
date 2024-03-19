/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:58 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/15 03:04:00 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	load_images(t_game *game)
{
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx,
			"textures/p_left.xpm", &game->textures[0].width,
			&game->textures[0].height);
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx,
			"textures/p_right.xpm", &game->textures[1].width,
			&game->textures[1].height);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->textures[2].width,
			&game->textures[2].height);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx,
			"textures/coins.xpm", &game->textures[3].width,
			&game->textures[3].height);
	game->textures[4].img = mlx_xpm_file_to_image(game->mlx,
			"textures/ground.xpm", &game->textures[4].width,
			&game->textures[4].height);
	game->textures[5].img = mlx_xpm_file_to_image(game->mlx,
			"textures/door_c.xpm", &game->textures[5].width,
			&game->textures[5].height);
	game->textures[6].img = mlx_xpm_file_to_image(game->mlx,
			"textures/door_o.xpm", &game->textures[6].width,
			&game->textures[6].height);
}
