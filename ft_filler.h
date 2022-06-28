/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:48:27 by akilk             #+#    #+#             */
/*   Updated: 2022/06/27 16:48:28 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include <stdio.h> // clean
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_token
{
	int		width;
	int		height;
	char	**data;
}				t_token;

typedef struct s_game
{
	char	me;
	char	enemy;
	int		width;
	int		height;
	char	**board;
}				t_game;

/* main.c */
int		main(void);

/* error.c */
int	error(char **str, char *msg);

/* read_meta.c */
int	get_player(t_game *game);

/* read_board.c */
int	get_board_size(t_game *game);
int	read_board(t_game *game);

/* read_token.c */
int	get_token_size(t_token *token);


#endif
