/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:45:44 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/18 02:20:11 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	render_map(t_game *game)
{
	game->row = 0;
	while (game->row < game->win_height)
	{
		game->col = 0;
		while (game->col < game->win_width)
		{
			draw_character(game);
			game->col++;
		}
		game->row++;
	}
}

void	render_player(t_game *game)
{
	t_texture	texture;

	game->i = game->player.x * 64;
	game->j = game->player.y * 64;
	if (game->player_movement == 100)
		texture = game->textures[1];
	else if (game->player_movement == 97)
		texture = game->textures[0];
	else if (game->prev_movement == 100)
		texture = game->textures[1];
	else if (game->prev_movement == 97)
		texture = game->textures[0];
	else
		texture = game->textures[1];
	game->prev_movement = game->player_movement;
	mlx_put_image_to_window(game->mlx, game->win, texture.img, game->i,
		game->j);
}

void	handle_game_logic(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->map[game->player.y][game->player.x] = '0';
		ft_printf("You have collected a coin\n");
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& no_more_collectibles(game) == 0)
	{
		ft_printf("  ****Mbroook 3lik a sat rb7ti hh****    \n");
		exit_game(game);
	}
}

int	update_frame(t_game *game)
{
	render_map(game);
	render_player(game);
	handle_game_logic(game);
	return (0);
}
