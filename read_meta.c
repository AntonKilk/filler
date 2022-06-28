/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_meta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:54:59 by akilk             #+#    #+#             */
/*   Updated: 2022/06/27 16:12:12 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

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
