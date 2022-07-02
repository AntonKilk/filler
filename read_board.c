/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 08:40:28 by akilk             #+#    #+#             */
/*   Updated: 2022/06/28 22:16:23 by akilk            ###   ########.fr       */
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
		printf("%s\n", game->board[i]);
		i++;
	}
	return (1);
}

int	read_board(t_game *game, char *line)
{
	if (!get_board_size(game, line))
		return(error(&line, "Error getting board size in read_board()"));
	game->board = (char **)ft_memalloc(sizeof (char *) * (game->height + 1));
	if (!game->board)
		return(error(&line, "Error allocating board in read_board()"));
	if (!make_map(game->board, game->height, game->width))
		return (error(&line, "Error creating board in read_board()"));
	return (1);
}