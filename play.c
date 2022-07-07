/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:01 by akilk             #+#    #+#             */
/*   Updated: 2022/07/06 09:49:44 by akilk            ###   ########.fr       */
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

// void	draw(t_game *game, t_token *token, int x, int y)
// {
// 	int	i;
// 	int	j;
// 	char	t;

// 	i = 0;
// 	while (i < token->height)
// 	{
// 		j = 0;
// 		while (j < token->width)
// 		{
// 			t = token->map[i][j];
// 			if (t != '.')
// 				game->board[i+y][x+j] = 'A';
// 			j++;
// 		}
// 		i++;
// 	}
// }

static int	try_put(t_game *game, t_token *token, t_coords start, t_coords end)
{
	int	x_start;

	x_start = start.x;
	// int run_draw = 0;
	while (start.y <= end.y)
	{
		start.x = x_start;
		while (start.x <= end.x)
		{
			if (can_put(game, token, start.x, start.y))
			{
				// if (run_draw == 4)
				// {
				// 	printf("here x: %d, y: %d\n", start.x, start.y);
				// 	draw(game, token, start.x, start.y);
				// 	// int i = 0;
				// 	// while (i < game->height)
				// 	// {
				// 	// 	printf("%s\n", game->board[i]);
				// 	// 	i++;
				// 	// }
				// }
				// run_draw++;
				// printf("x: %d, y: %d\n", start.x, start.y);
				game->result.x = start.x;
				game->result.y = start.y;
				return (1);
			}
			start.x++;
		}
		start.y++;
	}
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
	// printf("tryst x %d, y: %d\n", try_start.x, try_start.y);
	// printf("tryend x %d, y: %d\n", try_end.x, try_end.y);
	if (try_put(game, token, try_start, try_end))
		return (1);
	return (0);
}
