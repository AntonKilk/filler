/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:01 by akilk             #+#    #+#             */
/*   Updated: 2022/06/30 13:38:32 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"


// Find first cell from up left corner that contains my territory symbol
int	find_me(t_game *game)
{
	int		h;
	int		w;
	char	c;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			c = game->board[h][w];
			if (ft_toupper(c) == game->me)
			{
				game->place.x = w;
				game->place.y = h;
				return (1);
			}
			w++;
		}
		h++;
	}
	return (0);
}

int	is_overlap(char a, char b)
{
	if (a == b)
		return (1);
	return (0);
}

int	put_piece(t_game *game, t_token *token)
{
	t_coords	start;
	t_coords	end;
	int	w;
	int	h;
	int	overlaps;
	char	c;

	overlaps = 0;
	h = 0;
	start.y = game->place.y - token->dims.y;
	end.y = game->place.x + token->dims.y;
	end.x = game->place.x + token->dims.x;
	while (start.y <= end.y)
	{
		if (start.y++ < 0)
		w = 0;
		start.x = game->place.x - token->dims.x;
		while (start.x <= end.x)
		{
			if (start.x++ < 0)
				continue ;
			c = game->board[start.y][start.x];
			//overlaps with enemy
			if (is_overlap(ft_toupper(c), game->enemy))
				return (0);
			//overlaps with me
			if (is_overlap(ft_toupper(c), game->me))
				overlaps++;
			if (overlaps > 1)
				return (0);
		}
	}
	return (0);
}

int	try_put(t_game *game, t_token *token)
{
	int			w;
	int			h;
	t_coords	coords;

	//find first place on map to attach own detail
	if (!find_me(game))
		return (error(NULL, "My territory not found in try_put()"));
	//Check that counter of overlap return 1
	//chek that not crossing borders of board and enemy territory
	put_piece(game, token);
	return (0);
}
