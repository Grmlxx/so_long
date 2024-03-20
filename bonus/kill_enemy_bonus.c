/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:17:04 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/20 01:01:33 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	kill_enemy_right(t_game *game)
{
	int	i;

	i = 0;
	game->i = game->player.x * 64;
	game->j = game->player.y * 64;
	while (game->map[game->player.y][game->player.x + i])
	{
		if (game->map[game->player.y][game->player.x + i] == 'X')
		{
			game->map[game->player.y][game->player.x + i] = '0';
			break ;
		}
		i++;
	}
	update_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->textures[7].img,
		game->i, game->j);
}

void	kill_enemy_left(t_game *game)
{
	int	i;

	i = 0;
	game->i = game->player.x * 64;
	game->j = game->player.y * 64;
	while (game->player.x - i >= 0 && game->map[game->player.y][game->player.x
		- i])
	{
		if (game->map[game->player.y][game->player.x - i] == 'X')
		{
			game->map[game->player.y][game->player.x - i] = '0';
			break ;
		}
		i++;
	}
	update_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->textures[8].img,
		game->i, game->j);
}

void	kill_enemy_down(t_game *game)
{
	int	i;

	i = 0;
	game->i = game->player.x * 64;
	game->j = game->player.y * 64;
	while (game->player.y + i < game->win_height && game->map[game->player.y
			+ i][game->player.x])
	{
		if (game->map[game->player.y + i][game->player.x] == 'X')
		{
			game->map[game->player.y + i][game->player.x] = '0';
			break ;
		}
		i++;
	}
	update_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->textures[9].img,
		game->i, game->j);
}

void	kill_enemy_up(t_game *game)
{
	int	i;

	i = 0;
	game->i = game->player.x * 64;
	game->j = game->player.y * 64;
	while (game->player.y - i >= 0 && game->map[game->player.y
			- i][game->player.x])
	{
		if (game->map[game->player.y - i][game->player.x] == 'X')
		{
			game->map[game->player.y - i][game->player.x] = '0';
			break ;
		}
		i++;
	}
	update_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->textures[10].img,
		game->i, game->j);
}

void	free_enemy_images(t_game *game)
{
	game->i = 0;
	while (game->i < 8)
		mlx_destroy_image(game->mlx, game->enemy_textures[game->i++].img);
}
