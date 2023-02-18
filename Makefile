NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = so_long.c check_insid_map.c put_img_map.c move.c

MLX = -lmlx -framework OpenGL -framework Appkit

PRINTF = printf/ft_*.c

LINE = Line/*.c

all : $(NAME)
$(NAME) :
	@$(CC) $(FLAGS) $(SRC) $(LINE) $(PRINTF) $(MLX) -o $(NAME)

clean :
	@rm -f $(NAME)

fclean : clean
	@rm -f $(NAME)

re : fclean all