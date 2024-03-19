/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:58 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/19 03:48:05 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	load_images_gun_shot(t_game *game)
{
	game->textures[7].img = mlx_xpm_file_to_image(game->mlx,
			"textures/p_r_gun.xpm", &game->textures[7].width,
			&game->textures[7].height);
	game->textures[8].img = mlx_xpm_file_to_image(game->mlx,
			"textures/p_l_gun.xpm", &game->textures[8].width,
			&game->textures[8].height);
	game->textures[9].img = mlx_xpm_file_to_image(game->mlx,
			"textures/p_gun_d.xpm", &game->textures[9].width,
			&game->textures[9].height);
	game->textures[10].img = mlx_xpm_file_to_image(game->mlx,
			"textures/p_gun_up.xpm", &game->textures[10].width,
			&game->textures[10].height);
}

void	load_enemy_sprites(t_game *game)
{
	game->enemy_textures[0].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police.xpm", &game->enemy_textures[0].width,
			&game->enemy_textures[0].height);
	game->enemy_textures[1].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police1.xpm", &game->enemy_textures[1].width,
			&game->enemy_textures[1].height);
	game->enemy_textures[2].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police2.xpm", &game->enemy_textures[2].width,
			&game->enemy_textures[2].height);
	game->enemy_textures[3].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police3.xpm", &game->enemy_textures[3].width,
			&game->enemy_textures[3].height);
	game->enemy_textures[7].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police4.xpm", &game->enemy_textures[3].width,
			&game->enemy_textures[3].height);
	game->enemy_textures[6].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police5.xpm", &game->enemy_textures[3].width,
			&game->enemy_textures[3].height);
	game->enemy_textures[5].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police6.xpm", &game->enemy_textures[3].width,
			&game->enemy_textures[3].height);
	game->enemy_textures[4].img = mlx_xpm_file_to_image(game->mlx,
			"textures/police7.xpm", &game->enemy_textures[3].width,
			&game->enemy_textures[3].height);
}

void	load_images(t_game *game)
{
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx,
			"textures/pp_left.xpm", &game->textures[0].width,
			&game->textures[0].height);
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx,
			"textures/pp_right.xpm", &game->textures[1].width,
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
	load_images_gun_shot(game);
	load_enemy_sprites(game);
}
