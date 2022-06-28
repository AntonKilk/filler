/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 08:40:28 by akilk             #+#    #+#             */
/*   Updated: 2022/06/27 16:54:09 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	get_board_size(t_game *game)
{
	char		*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (error(NULL, "Input error in get_board_size()"));
	if (!ft_strstr(line, "Plateau"))
		return (error(&line, "Failed to find board size in get_board_size()"));
	game->height = ft_atoi(ft_strchr(line, ' '));
	game->width = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	if (!game->height || !game->width)
		return (error(NULL, "Error, invalid board size in get_board_size()"));
	return (1);
}

int	make_board(t_game *game)
{
	int		i;

	game->board = (char **)ft_memalloc(sizeof (char *) * (game->height + 1));
	if (!game->board)
		return(error(NULL, "Error allocating board in make_board()"));
	i = 0;
	while (i < game->height)
	{
		game->board[i] = ft_strnew(sizeof (char) * game->width);
		if (!game->board[i])
			return(error(game->board, "Error allocating row in make_board()"));
		i++;
	}
	return (1);
}

//validate_board()
// {
// 	board->width = ft_strlen(row);
// 	check symbols
// }

int	read_board(t_game *game)
{

	char	*row;
	int		ret;
	int		i;

	if (!make_board(game))
		return (error(NULL, "Error making board in read_board()"));
	i = 0;
	row = NULL;
	get_next_line(0, &row); //skip line 01234...
	while (i < game->height)
	{
		if (get_next_line(0, &row) <= 0)
			return (error(game->board, "Error reading line in read_board()"));
		ft_memcpy(game->board[i], row + 4, game->width);
		printf("%s\n", game->board[i]);
		//add validation of symbols and width
		ft_strdel(&row);
		i++;
	}
	return (1);
}
