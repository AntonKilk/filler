/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:01 by akilk             #+#    #+#             */
/*   Updated: 2022/07/16 19:44:08 by akilk            ###   ########.fr       */
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

int	find_closest(t_coords me, t_coords closest)
{
	int	diffX;
	int	diffY;
	int	result;

	diffX = me.x - closest.x;
	diffY = me.y - closest.y;
	// printf("diffX: %d\n", diffX);
	// printf("diffY: %d\n", diffY);
	/* the less the better(closer) */
	result = (diffX * diffX) + (diffY * diffY);
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

// calculate distance to nearest enemy
t_coords find_enemy(t_game *game, t_token *token, t_coords start)
{
	t_coords	curr;
	t_coords	up;
	t_coords	down;
	t_coords	closest;

	curr.x = start.x + token->start.x;
	curr.y = start.y + token->start.y;
	// printf("current location Y:%d, X:%d\n", curr.y, curr.x);
	/* search up */
	up = searchup(game, curr);
	/* search down */
	down = searchdown(game, curr);
	/* find closest */
	if (up.x < 0 && up.y < 0)
		closest = down;
	else if (down.x < 0 && down.y < 0)
		closest = up;
	else
	{
		if (find_closest(curr, up) < find_closest(curr, down))
			closest = up;
		else
			closest = down;
	}
	closest.x -= token->start.x;
	closest.y -= token->start.y;
	return (closest);
}

int	try_put(t_game *game, t_token *token, t_coords start, t_coords end)
{
	int	tmp;
	int	result;
	int	OK;
	t_coords	closest;

	result = game->width * game->height * 4; //4 is enough?
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
				/* where is the closest enemy up or down? */
				closest = find_enemy(game, token, start);
				// fprintf(stderr, "current origing Y:%d,X:%d\n", start.y, start.x);
				// fprintf(stderr, "closest Y:%d,X:%d\n", closest.y, closest.x);
				if (find_closest(start, closest) < result)
				{
					result = find_closest(start, closest);
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
