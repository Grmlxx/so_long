/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:49 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/19 23:39:35 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	get_map(t_game *game)
{
	game->fd = open(game->av[1], O_RDONLY);
	if (game->fd == -1)
		error_msg("There is no file with that name");
	empty_file(game);
	game->w = 1;
	while (1)
	{
		game->str = get_next_line(game->fd);
		if (game->str == NULL)
			break ;
		free(game->str);
		game->w++;
	}
	game->fd = open(game->av[1], O_RDONLY);
	game->map = malloc(((game->w + 1) * sizeof(char *)));
	game->w = 0;
	while (1)
	{
		game->map[game->w] = get_next_line(game->fd);
		if (game->map[game->w] == NULL)
			break ;
		game->w++;
	}
	game->win_height = game->w;
	game->win_width = ft_strlen(game->map[0]) - 1;
}

void	get_player_position(t_game *game)
{
	game->row = 0;
	while (game->map[game->row])
	{
		game->col = 0;
		while (game->map[game->row][game->col])
		{
			if (game->map[game->row][game->col] == 'P')
			{
				game->player.x = game->col;
				game->player.y = game->row;
				return ;
			}
			game->col++;
		}
		game->col = 0;
		game->row++;
	}
}
