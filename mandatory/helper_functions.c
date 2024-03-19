/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:45:51 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/17 22:15:03 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

t_game	initialize_variables(char **av)
{
	t_game	game;

	game = (t_game){0};
	game.av = av;
	return (game);
}

void	bye_bye(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	free_map(game);
	exit(1);
}

int	no_more_collectibles(t_game *game)
{
	int	row;
	int	col;

	game->i = 0;
	row = 0;
	while (row < game->win_height)
	{
		col = 0;
		while (col < game->win_width)
		{
			if (game->map[row][col] == 'C')
				game->i++;
			col++;
		}
		row++;
	}
	return (game->i);
}

void	draw_character(t_game *game)
{
	t_texture	texture;

	if (game->map[game->row][game->col] == '0'
		|| game->map[game->row][game->col] == 'P')
		texture = game->textures[4];
	else if (game->map[game->row][game->col] == '1')
		texture = game->textures[2];
	else if (game->map[game->row][game->col] == 'C')
		texture = game->textures[3];
	else if (game->map[game->row][game->col] == 'E')
	{
		if (no_more_collectibles(game) == 0)
			texture = game->textures[6];
		else
			texture = game->textures[5];
	}
	mlx_put_image_to_window(game->mlx, game->win, texture.img, game->col * 64,
		game->row * 64);
}

void	empty_file(t_game *game)
{
	game->str = get_next_line(game->fd);
	if (game->str == NULL)
		error_msg("The file is empty");
	free(game->str);
}
