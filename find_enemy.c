/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:49:33 by akilk             #+#    #+#             */
/*   Updated: 2022/07/18 11:50:23 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	find_closest(t_coords me, t_coords closest)
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

t_coords	find_enemy(t_game *game, t_coords start)
{
	t_coords	up;
	t_coords	down;
	t_coords	closest;

	up = searchup(game, start);
	down = searchdown(game, start);
	if (up.x < 0 && up.y < 0)
		closest = down;
	else if (down.x < 0 && down.y < 0)
		closest = up;
	else
	{
		if (find_closest(start, up) < find_closest(start, down))
			closest = up;
		else
			closest = down;
	}
	return (closest);
}

int	check_all_points(t_game *game, t_token *token, t_coords start)
{
	int			i;
	int			j;
	int			result;
	int			a;
	int			b;
	t_coords	closest;

	a = start.x;
	b = start.y;
	result = game->width * game->height;
	i = 0;
	while (i < token->height)
	{
		j = 0;
		while (j < token->width)
		{
			if (token->map[i][j] != '.')
			{
				start.x = a + j;
				start.y = b + i;
				closest = find_enemy(game, start);
				if (find_closest(start, closest) < result)
					result = find_closest(start, closest);
			}
			j++;
		}
		i++;
	}
	return (result);
}
