/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:23:57 by akilk             #+#    #+#             */
/*   Updated: 2022/07/04 09:55:12 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	validate_line(int width, char *line, char *str)
{
	if (width != ft_strlen(line))
		return (0);
	while (*line)
	{
		if (!ft_strchr(str, *line))
			return (0);
		line++;
	}
	return (1);
}

int	get_player(t_game *game)
{
	char	*line;
	char	*p;

	if (game->me != 0)
		return (1);
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (error(NULL, "Error reading players"));
	p = ft_strchr(line, 'p');
	if (!p++)
		return (error(&line, "Error in get_players()"));
	if (*p == '1')
	{
		game->me = 'O';
		game->enemy = 'X';
	}
	else if (*p == '2')
	{
		game->me = 'X';
		game->enemy = 'O';
	}
	else
		return (error(&line, "Error in get_players()"));
	ft_strdel(&line);
	return (1);
}

int	make_map(char **map, int height, int width)
{
	int		i;

	i = 0;
	while (i < height)
	{
		map[i] = ft_strnew(sizeof (char) * width);
		if (!map[i])
			return(error(map, "Error allocating row in make_map()"));
		i++;
	}
	return (1);
}

int read_data(t_game *game, t_token *token)
{
	char	*line;

	line = NULL;
	if (!game->height && !game->width)
	{
		if (!read_board(game, line))
			return(error(&line, "Error reading board in read_data()"));
	}
	while (get_next_line(0, &line))
	{
		if (!ft_strstr(line, "012345"))
			continue ;
		if (!fill_board(game, &line))
			return (error (&line, "Error filling board in read_data()"));
		get_next_line(0, &line);
		break ;
	}
	if (!get_zone_shape(game))
		return (error (&line, "Error getting zone shape in read_board()"));
	if (!read_token(token, &line))
		return (error(NULL, "Error reading token in read_data()"));
	ft_strdel(&line);
	return (1);
}
