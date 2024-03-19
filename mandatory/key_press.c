/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:16 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/15 03:03:58 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	is_valid_position(int x, int y, t_game *game)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'E' && no_more_collectibles(game) != 0)
		return (0);
	return (1);
}

void	handle_player_movement(int keycode, t_game *game)
{
	game->new_x = game->player.x;
	game->new_y = game->player.y;
	game->player_movement = keycode;
	if (keycode == 115 || keycode == 'W')
		game->new_y++;
	else if (keycode == 97 || keycode == 'A')
		game->new_x--;
	else if (keycode == 119 || keycode == 'S')
		game->new_y--;
	else if (keycode == 100 || keycode == 'D')
		game->new_x++;
	if (is_valid_position(game->new_x, game->new_y, game))
	{
		game->player.x = game->new_x;
		game->player.y = game->new_y;
		game->movements++;
		ft_printf("Number of moves: %d\n", game->movements);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119 || keycode == 'S')
		handle_player_movement(119, game);
	else if (keycode == 97 || keycode == 'A')
		handle_player_movement(97, game);
	else if (keycode == 115 || keycode == 'W')
		handle_player_movement(115, game);
	else if (keycode == 100 || keycode == 'D')
		handle_player_movement(100, game);
	update_frame(game);
	return (0);
}
