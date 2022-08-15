/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:49:54 by akilk             #+#    #+#             */
/*   Updated: 2022/08/15 15:53:30 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	calc_dist(t_coords me, t_coords closest)
{
	int	diffx;
	int	diffy;
	int	result;

	diffx = ft_abs(me.x - closest.x);
	diffy = ft_abs(me.y - closest.y);
	result = diffx + diffy;
	return (result);
}

t_coords	searchup(t_game *game, t_coords curr)
{
	int	board_w;

	board_w = game->width;
	while (curr.y >= 0)
	{
		while (curr.x >= 0)
		{
			if (ft_toupper(game->board[curr.y][curr.x]) == game->enemy)
				return (curr);
			curr.x--;
		}
		curr.x = board_w;
		curr.y--;
	}
	curr.y = -1;
	curr.x = -1;
	return (curr);
}

t_coords	searchdown(t_game *game, t_coords curr)
{
	while (curr.y < game->height)
	{
		while (curr.x < game->width)
		{
			if (ft_toupper(game->board[curr.y][curr.x]) == game->enemy)
				return (curr);
			curr.x++;
		}
		curr.x = 0;
		curr.y++;
	}
	curr.y = -1;
	curr.x = -1;
	return (curr);
}
