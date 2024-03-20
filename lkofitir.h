/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lkofitir.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:10:55 by alamaoui          #+#    #+#             */
/*   Updated: 2024/03/20 00:42:28 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LKOFITIR_H
# define LKOFITIR_H

# include <X11/Xlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_texture
{
	void		*img;
	int			width;
	int			height;
}				t_texture;

typedef struct s_player
{
	int			x;
	int			y;

}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			player_movement;
	int			prev_movement;
	char		**av;
	t_texture	textures[11];
	t_texture	enemy_textures[8];
	t_player	player;
	int			movements;
	int			win_height;
	int			win_width;
	int			exits_count;
	int			coins_count;
	int			p_count;
	int			wall_count;
	int			g_count;
	int			police_count;
	int			i;
	int			j;
	int			row;
	int			col;
	int			w;
	int			fd;
	int			new_x;
	int			new_y;
	char		*str;
	char		**new_map;
	char		*moves;
}				t_game;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void			get_map(t_game *game);
void			get_player_position(t_game *game);
int				check_ber(char **av, t_game *game);
int				is_closed_map(t_game *game);
int				is_closed_map(t_game *game);
void			validate_map_characters(t_game *game);
void			is_rectangular(t_game *game);
void			copy_map(t_game *game);
void			flood(char **str, int x, int y);
void			check_map(char **str, t_game *game);
void			map_parsing(t_game *game);
void			create_window(t_game *game);
int				exit_game(t_game *game);
t_game			initialize_variables(char **av);
void			bye_bye(char *str, t_game *game);
int				no_more_collectibles(t_game *game);
void			draw_character(t_game *game);
int				is_valid_position(int x, int y, t_game *game);
void			handle_player_movement(int keycode, t_game *game);
int				key_press(int keycode, t_game *game);
void			load_images(t_game *game);
void			render_map(t_game *game);
void			render_player(t_game *game);
void			handle_game_logic(t_game *game);
int				update_frame(t_game *game);
void			free_map(t_game *game);
void			free_new_map(t_game *game);
void			free_images(t_game *game);
void			check_character(t_game *game);
void			error_msg(char *str);
void			empty_file(t_game *game);

size_t			ft_strlen(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
char			*get_next_line(int fd);

int				ft_putformat(char specifier, va_list args);
int				ft_printf(const char *format, ...);
int				ft_putchar(int c);
int				ft_puthexl(unsigned long n);
int				ft_puthexu(unsigned long n);
int				ft_putnbr(int n);
int				ft_putpointer(void *p);
int				ft_putstr(char *str);
int				ft_putunsigned(unsigned int n);

char			*ft_itoa(int n);
void			kill_enemy_right(t_game *game);
void			kill_enemy_left(t_game *game);
void			kill_enemy_down(t_game *game);
void			kill_enemy_up(t_game *game);
int				animate_enemy(t_game *game);
void			free_enemy_images(t_game *game);

#endif