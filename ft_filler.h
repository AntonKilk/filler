/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:48:27 by akilk             #+#    #+#             */
/*   Updated: 2022/06/29 13:27:48 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include <stdio.h> // clean
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_coords
{
	int	x;
	int	y;
}			t_coords;

typedef struct s_token
{
	int			width;
	int			height;
	t_coords	start;
	t_coords	end;
	char		**map;
	t_coords	dims;
}				t_token;

typedef struct s_game
{
	char		me;
	char		enemy;
	int			width;
	int			height;
	t_coords	place;
	char		**board;
}				t_game;

/* main.c */
int		main(void);
int	init(t_game *game, t_token *token);
int	error(char **str, char *msg);

/* read.c */
int read_data(t_game *game, t_token *token);
int	get_player(t_game *game);
int	make_map(char **map, int height, int width);
int	validate_line(int width, char *line, char *str);

/* read_board.c */
int	get_board_size(t_game *game, char *line);
int	fill_board(t_game *game, char **line);
int	make_board(t_game *game);
int	read_board(t_game *game, char *line);

/* read_token.c */
int	get_token_size(t_token *token, char *line);
int	fill_token(t_token *token, char **line);
int	read_token(t_token *token, char **line);

/* play.c */
int	try_put(t_game *game, t_token *token);

#endif
