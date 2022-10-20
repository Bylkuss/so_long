
NAME = so_long

LIBFT = include/libft/libft.a

LIBFT_PATH = include/libft/

SRCS_PATH = srcs/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRCS_FILES = srcs/main.c srcs/maps.c srcs/game.c srcs/utils.c srcs/checks.c include/get_next_line/get_next_line.c \
			include/get_next_line/get_next_line_utils.c srcs/img.c srcs/moves.c srcs/bonus.c

#SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS = $(SRCS_FILES:.c=.o)


all: 	$(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) COMPILED! 💯 $(DEFAULT)"


$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "\n$(GREEN)$(NAME) created!$(DEFAULT) 💯"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

debug:		$(NAME)
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "\n$(GREEN)$(NAME) created!$(DEFAULT) 💯"
	@$(CC) $(CFLAGS) -g3  -fsanitize=address $(OBJS) $(LIBFT) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@echo "\n$(YELLOW)Object files deleted!$(DEFAULT) 💯"

fclean:	clean
	@$(RM) $(NAME) $(LIBFT)



re:		fclean all



.PHONY:	all clean libft fclean re



#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
COMMIT = $(shell date "+%d %B %T")

