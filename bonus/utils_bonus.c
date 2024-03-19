/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:34:23 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/19 03:47:43 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

void	free_map(t_game *game)
{
	game->i = 0;
	while (game->map[game->i] != NULL)
	{
		free(game->map[game->i]);
		game->i++;
	}
	free(game->map);
}

void	free_new_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->new_map[i] != NULL)
	{
		free(game->new_map[i]);
		i++;
	}
	free(game->new_map);
}

void	free_images(t_game *game)
{
	game->i = 0;
	while (game->i < 11)
		mlx_destroy_image(game->mlx, game->textures[game->i++].img);
}

void	check_character(t_game *game)
{
	if (game->map[game->row][game->col] == 'E')
		game->exits_count++;
	else if (game->map[game->row][game->col] == 'C')
		game->coins_count++;
	else if (game->map[game->row][game->col] == 'P')
		game->p_count++;
	else if (game->map[game->row][game->col] == '0')
		game->g_count++;
	else if (game->map[game->row][game->col] == '1')
		game->wall_count++;
	else if (game->map[game->row][game->col] == 'X')
		game->police_count++;
	else
		bye_bye("Invalid map character", game);
}

void	error_msg(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}
