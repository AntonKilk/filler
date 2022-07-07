.PHONY: all, clean, fclean, re

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

LIBFT = ./libft/libft.a

NAME = akilk.filler

SRCS = main.c read.c read_board.c read_token.c play.c

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
