/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:16 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/19 03:25:29 by alamaoui         ###   ########.fr       */
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
	if (keycode == 65361)
		kill_enemy_left(game);
	else if (keycode == 65363)
		kill_enemy_right(game);
	else if (keycode == 65364)
		kill_enemy_down(game);
	else if (keycode == 65362)
		kill_enemy_up(game);
	return (0);
}

static int	lenght(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = lenght(nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nbr != 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
