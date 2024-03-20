/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_for_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:06:36 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/20 00:08:38 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	copy_map(t_game *game)
{
	int	i;

	i = 0;
	game->new_map = malloc((game->win_height + 1) * sizeof(char *));
	while (i < game->win_height)
	{
		game->new_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->new_map[i] = NULL;
}

void	flood(char **str, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (str[y][x] == '1' || str[y][x] == 'F' || str[y][x] == 'E')
		return ;
	else
	{
		str[y][x] = 'F';
		flood(str, x + 1, y);
		flood(str, x - 1, y);
		flood(str, x, y + 1);
		flood(str, x, y - 1);
	}
}

int	check_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			if (map[i][j] == 'E' && map[i - 1][j] != 'F' && map[i + 1][j] != 'F'
				&& map[i][j - 1] != 'F' && map[i][j + 1] != 'F')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map(char **str, t_game *game)
{
	flood(game->new_map, game->player.x, game->player.y);
	if (check_path(str))
	{
		free_new_map(game);
		bye_bye("The game path is not valid", game);
	}
}
