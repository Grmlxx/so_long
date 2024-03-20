NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = gnl/get_next_line.c \
      gnl/get_next_line_utils.c \
      printf/ft_printf.c \
      printf/ft_putchar.c \
      printf/ft_puthexl.c \
      printf/ft_puthexu.c \
      printf/ft_putnbr.c \
      printf/ft_putpointer.c \
      printf/ft_putstr.c \
      printf/ft_putunsigned.c \
      mandatory/read_the_map.c \
      mandatory/parsing.c \
      mandatory/load_images.c \
      mandatory/create_window.c \
      mandatory/update_frame.c \
      mandatory/key_press.c \
      mandatory/exit_game.c \
      mandatory/helper_functions.c \
      mandatory/utils.c \
	  mandatory/path_for_characters.c \
      mandatory/main.c

OBJS = $(SRC:.c=.o)

BSRCS = gnl/get_next_line.c \
      	gnl/get_next_line_utils.c \
      	printf/ft_printf.c \
     	printf/ft_putchar.c \
   	   	printf/ft_puthexl.c \
   	   	printf/ft_puthexu.c \
   	   	printf/ft_putnbr.c \
    	printf/ft_putpointer.c \
      	printf/ft_putstr.c \
      	printf/ft_putunsigned.c \
      	bonus/parsing_bonus.c \
		bonus/read_the_map_bonus.c \
      	bonus/load_images_bonus.c \
      	bonus/create_window_bonus.c \
      	bonus/update_frame_bonus.c \
		bonus/kill_enemy_bonus.c\
      	bonus/key_press_bonus.c \
      	bonus/exit_game_bonus.c \
      	bonus/helper_functions_bonus.c \
      	bonus/utils_bonus.c \
	  	bonus/path_for_characters_bonus.c \
		bonus/animation_bonus.c \
      	bonus/main_bonus.c

BOBJS = $(BSRCS:.c=.o)

LIBS = -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

bonus: $(BOBJS)
		$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BOBJS) $(LIBS)

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all