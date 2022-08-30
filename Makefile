NAME = akilk.filler
SRCS = main.c\
	play.c\
	read_board.c\
	read_token.c\
	read.c\
	search_utils.c\
	find_enemy.c\

OBJS = main.o\
	play.o\
	read_board.o\
	read_token.o\
	read.o\
	search_utils.o\
	find_enemy.o\

HDR = ft_filler.h
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
