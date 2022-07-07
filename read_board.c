/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 08:40:28 by akilk             #+#    #+#             */
/*   Updated: 2022/07/07 15:26:40 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	get_board_size(t_game *game, char *line)
{
	if (get_next_line(0, &line) <= 0)
		return (error(NULL, "Input error in get_board_size()"));
	if (!ft_strstr(line, "Plateau"))
		return (error(&line, "Failed to find board size in get_board_size()"));
	game->height = ft_atoi(ft_strchr(line, ' '));
	game->width = ft_atoi(ft_strrchr(line, ' '));
	if (!game->height || !game->width)
		return (error(NULL, "Error, invalid board size in get_board_size()"));
	return (1);
}

int	fill_board(t_game *game, char **line)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		get_next_line(0, line);
		ft_memcpy(game->board[i], *line + 4, game->width);
		if (!game->board[i])
			return(error(game->board, "Error allocating game->board in fill_board()"));
		if (!validate_line(game->width,game->board[i], ".xXoO"))
			return (error(game->board, "Error validating line in fill_board()"));
		// printf("%s\n", game->board[i]);
		i++;
	}
	return (1);
}

int	get_zone_shape(t_game *game)
{
	int		w;
	int		h;
	char	c;

	h = 0;
	game->start.x = game->width;
	game->start.y = game->height;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			c = game->board[h][w];
			if (ft_toupper(c) == game->me)
			{
				game->start.x = ft_min(w, game->start.x);
				game->end.x = ft_max(w, game->end.x);
				game->start.y = ft_min(h, game->start.y);
				game->end.y = ft_max(h, game->end.y);
			}
			w++;
		}
		h++;
	}
	game->dims.x = game->end.x - game->start.x + 1;
	game->dims.y = game->end.y - game->start.y + 1;
	return (1);
}

int	read_board(t_game *game, char *line)
{
	ft_bzero(&(game->start), sizeof(game->start));
	ft_bzero(&(game->end), sizeof(game->end));
	if (!get_board_size(game, line))
		return(error(&line, "Error getting board size in read_board()"));
	game->board = (char **)ft_memalloc(sizeof (char *) * (game->height + 1));
	if (!game->board)
		return(error(&line, "Error allocating board in read_board()"));
	if (!make_map(game->board, game->height, game->width))
		return (error(&line, "Error creating board in read_board()"));
	return (1);
}
