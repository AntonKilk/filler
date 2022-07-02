/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:01 by akilk             #+#    #+#             */
/*   Updated: 2022/07/02 18:14:35 by akilk            ###   ########.fr       */
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

// int	is_overlap(char a, char b)
// {
// 	if (a == b)
// 		return (1);
// 	return (0);
// }

void	clear(char **board, t_token *token, int x, int y)
{
	int		i;
	int		j;
	char	t;
	char	b;

	i = 0;
	while (i < token->height)
	{
		j = 0;
		while (j < token->width)
		{
			t = token->map[j][i];
			b = board[i+y][j+x];
			if (t != '.' && t == b)
				b = '.';
			j++;
		}
		i++;
	}
}

static int	try_putput(t_game *game, t_token *token, int x, int y)
{
	int	i;
	int	j;
	int	overlap;
	char	t;
	int	remove_dot;
	int	dot;

	overlap = 0;
	i = 0;
	remove_dot = 0;
	dot = 0;
	while (i < token->dims.y)
	{
		j = 0;
		while (j < token->dims.x)
		{
			t = token->map[i + token->start.y][j + token->start.x];
			if (t == '.' && remove_dot == 0)
				dot--;
			// printf("t: %c, b: %c\n", t, b);
			if (t != '.')
			{
				//printf("t: %c, b: %c\n", t, b);
				remove_dot = 1;
				if ((x + j >= game->width) || (y + i >= game->height)
					|| ft_toupper(game->board[i+y][x+j+dot]) == game->enemy)
					return (-1);
				// else if (overlap > 1)
				// 	return (-1);
				else if (ft_toupper(game->board[i+y][x+j+dot]) == game->me)
					overlap++;
				game->board[i+y][x+j+dot] = game->me;
			}
			j++;
		}
		i++;
	}
	printf("overlap: %d\n", overlap);
	return (0);
}

int	try_put(t_game *game, t_token *token)
{
	//find first place on map to attach own detail
	if (!find_me(game))
		return (error(NULL, "My territory not found in try_put()"));
	try_putput(game, token, game->place.x, game->place.y);
	printf("After placement\n");
	int i = 0;
	while (i < game->height)
	{
		printf("%s\n", game->board[i]);
		i++;
	}
	return (0);
}
