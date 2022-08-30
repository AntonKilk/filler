/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:01 by akilk             #+#    #+#             */
/*   Updated: 2022/08/30 13:34:42 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	space_found(t_coords curr, t_game *game, t_token *token, t_coords start)
{
	if (curr.x < 0 || curr.y < 0)
		return (0);
	else if (start.x + token->dims.x + token->start.x > game->width
		|| start.y + token->dims.y + token->start.y > game->height)
		return (0);
	else if (ft_toupper(game->board[curr.y][curr.x]) == game->enemy)
		return (0);
	return (1);
}

int	count_overlaps(t_coords curr, t_game *game, int *overlap)
{
	if (ft_toupper(game->board[curr.y][curr.x]) == game->me)
		(*overlap)++;
	return (*overlap);
}

int	can_put(t_game *game, t_token *token, t_coords start)
{
	t_coords	curr;
	int			overlap;
	int			i;
	int			j;

	i = -1;
	overlap = 0;
	while (++i < token->height)
	{
		j = -1;
		while (++j < token->width)
		{
			if (token->map[i][j] != '.')
			{
				curr.x = start.x + j;
				curr.y = start.y + i;
				if (!space_found(curr, game, token, start))
					return (0);
				else if (count_overlaps(curr, game, &overlap) > 1)
					return (0);
			}
		}
	}
	return (overlap == 1);
}

int	try_put(t_game *game, t_token *token, t_coords start, t_coords end)
{
	int	tmp;
	int	ok;
	int	result;

	result = game->width * game->height;
	tmp = start.x;
	ok = 0;
	while (start.y <= end.y)
	{
		start.x = tmp;
		while (start.x <= end.x)
		{
			if (can_put(game, token, start))
			{
				ok = 1;
				result = get_closest(game, token, start, result);
			}
			start.x++;
		}
		start.y++;
	}
	return (ok);
}

int	try_solve(t_game *game, t_token *token)
{
	t_coords	try_start;
	t_coords	try_end;

	try_start.x = game->start.x - token->end.x;
	try_start.y = game->start.y - token->end.y;
	try_end.x = game->end.x - token->start.x;
	try_end.y = game->end.y - token->start.y;
	if (try_put(game, token, try_start, try_end))
		return (1);
	return (0);
}
