/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:24 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/19 03:31:24 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkofitir.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_msg("finahiya lmap!!");
	game = initialize_variables(av);
	get_map(&game);
	get_player_position(&game);
	map_parsing(&game);
	create_window(&game);
	load_images(&game);
	update_frame(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, exit_game, &game);
	mlx_loop_hook(game.mlx, animate_enemy, &game);
	mlx_loop(game.mlx);
}
