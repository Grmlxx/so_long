/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:40:18 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/16 21:51:04 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	check_ber(char **av, t_game *game)
{
	game->i = 0;
	game->j = 0;
	while (av[1][game->i])
	{
		if (av[1][game->i] == '.')
			game->j++;
		game->i++;
	}
	if (game->j != 1)
		bye_bye("You've forgot .ber", game);
	game->i = 0;
	while (av[1][game->i] != '.')
		game->i++;
	if (av[1][game->i + 1] == 'b' && av[1][game->i + 2] == 'e' && av[1][game->i
		+ 3] == 'r')
		return (0);
	else
	{
		bye_bye("Map name is not valid!", game);
		return (1);
	}
}

int	is_closed_map(t_game *game)
{
	game->i = 0;
	while (game->i < game->win_width)
	{
		if (game->map[0][game->i] != '1' || game->map[game->win_height
			- 1][game->i] != '1')
			bye_bye("The map is not closed.", game);
		game->i++;
	}
	game->i = 1;
	while (game->i < game->win_height - 1)
	{
		if (game->map[game->i][0] != '1' || game->map[game->i][game->win_width
			- 1] != '1')
			bye_bye("The map is not surrounded by walls.", game);
		game->i++;
	}
	return (1);
}

void	validate_map_characters(t_game *game)
{
	game->row = 0;
	while (game->row < game->win_height)
	{
		game->col = 0;
		while (game->col < game->win_width)
		{
			check_character(game);
			game->col++;
		}
		game->row++;
	}
	if (game->exits_count != 1 || game->coins_count < 1 || game->p_count != 1)
		bye_bye("1 exit, at least 1 collectible, 1 player.", game);
}

void	is_rectangular(t_game *game)
{
	game->i = 0;
	game->j = 0;
	while (game->i < game->win_height - 1)
	{
		game->j = ft_strlen(game->map[game->i]) - 1;
		if (game->j != game->win_width)
			bye_bye("Map is not rectangular", game);
		game->i++;
	}
	game->j = ft_strlen(game->map[game->i]);
	if (game->j != game->win_width)
		bye_bye("Map is not rectangular", game);
}

void	map_parsing(t_game *game)
{
	check_ber(game->av, game);
	is_rectangular(game);
	validate_map_characters(game);
	is_closed_map(game);
	copy_map(game);
	check_map(game->new_map, game);
	free_new_map(game);
}
