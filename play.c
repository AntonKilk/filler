/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:01 by akilk             #+#    #+#             */
/*   Updated: 2022/07/15 20:54:17 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	can_put(t_game *game, t_token *token, int x, int y)
{
	int	i;
	int	j;
	char	t;
	int	overlap;

	i = 0;
	overlap = 0;
	while (i < token->height)
	{
		j = 0;
		while (j < token->width)
		{
			t = token->map[i][j];
			if (t != '.')
			{
				if (x + j < 0 || y + i < 0)
					return (0);
				else if (x + token->dims.x + token->start.x > game->width || y + token->dims.y + token->start.y > game->height)
					return (0);
				else if (ft_toupper(game->board[i+y][x+j]) == game->enemy)
					return (0);
				else if (ft_toupper(game->board[i+y][x+j]) == game->me)
					overlap++;
				else if (overlap > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	if (overlap == 1)
		return (1);
	return (0);
}

int	find_closest(t_coords enemy, t_coords me)
{
	int	diffX;
	int	diffY;
	int	result;
	//enemy_end is always in opposite dir?
	diffX = ft_abs(me.x - enemy.x);
	diffY = ft_abs(me.y - enemy.y);
	/* the less the better(closer) */
	result = (diffX * diffX) + (diffY * diffY);
	return (result);
}

int	try_put(t_game *game, t_token *token, t_coords start, t_coords end)
{
	int	tmp;
	int	result;
	int	OK;

	result = game->width * game->height * 4;
	tmp = start.x;
	OK = 0;
	while (start.y <= end.y)
	{
		start.x = tmp;
		while (start.x <= end.x)
		{
			if (can_put(game, token, start.x, start.y))
			{
				OK = 1;
				if (find_closest(game->enemy_end, start) < result)
				{
					result = find_closest(game->enemy_end, start);
					game->result.x = start.x;
					game->result.y = start.y;
				}
			}
			start.x++;
		}
		start.y++;
	}
	if (OK)
		return (1);
	else
		return (0);
}

int	try_solve(t_game *game, t_token *token)
{
	t_coords try_start;
	t_coords try_end;

	try_start.x = game->start.x - token->end.x;
	try_start.y = game->start.y - token->end.y;
	try_end.x = game->end.x - token->start.x;
	try_end.y = game->end.y - token->start.y;
	if (try_put(game, token, try_start, try_end))
		return (1);
	return (0);
}
