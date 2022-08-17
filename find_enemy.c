/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:49:33 by akilk             #+#    #+#             */
/*   Updated: 2022/08/17 11:26:39 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

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
		if (calc_dist(start, up) < calc_dist(start, down))
			closest = up;
		else
			closest = down;
	}
	return (closest);
}

void	get_result(t_game *game, t_coords start, int *result)
{
	t_coords	closest;

	closest = find_enemy(game, start);
	if (calc_dist(start, closest) < *result)
		*result = calc_dist(start, closest);
}

int	try_all_points(t_game *game, t_token *token, t_coords start)
{
	int			i;
	int			j;
	int			result;
	int			a;
	int			b;

	a = start.x;
	b = start.y;
	result = game->width * game->height;
	i = -1;
	while (++i < token->height)
	{
		j = -1;
		while (++j < token->width)
		{
			if (token->map[i][j] != '.')
			{
				start.x = a + j;
				start.y = b + i;
				get_result(game, start, &result);
			}
		}
	}
	return (result);
}

int	get_closest(t_game *game, t_token *token, t_coords start, int result)
{
	if (try_all_points(game, token, start) < result)
	{
		result = try_all_points(game, token, start);
		game->result.x = start.x;
		game->result.y = start.y;
	}
	return (result);
}
