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
LIBFTDIR = libft/
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. $(LIBFT)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all
