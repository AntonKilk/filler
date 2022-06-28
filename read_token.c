/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:41:18 by akilk             #+#    #+#             */
/*   Updated: 2022/06/27 16:55:30 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	get_token_size(t_token *token)
{
	char		*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (error(NULL, "Input error in get_token_size()"));
	if (!ft_strstr(line, "Piece"))
		return (error(&line, "Failed to find token size in get_token_size()"));
	token->height = ft_atoi(ft_strchr(line, ' '));
	token->width = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	if (!token->height || !token->width)
		return (error(NULL, "Error, invalid board size in get_token_size()"));
	return (1);
}

int	make_token(t_game *game)
{
	int		i;

	token->data = (char **)ft_memalloc(sizeof (char *) * (token->height + 1));
	if (!token->data)
		return(error(NULL, "Error allocating token in make_token()"));
	i = 0;
	while (i < token->height)
	{
		token->data[i] = ft_strnew(sizeof (char) * token->width);
		if (!token->data[i])
			return(error(token->data, "Error allocating row in make_token()"));
		i++;
	}
	return (1);
}

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
