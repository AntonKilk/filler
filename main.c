/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:53 by akilk             #+#    #+#             */
/*   Updated: 2022/07/14 16:08:30 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	freeall(t_game *game, t_token *token)
{
	int	i;

	i = 0;
	if (game->board)
	{
		while (game->board[i])
		{
			printf("in board\n");
			free(game->board[i++]);
		}
		//ft_strdel(game->board);
	}
	i = 0;
	if (token->map)
	{
		while (token->map[i])
		{
			printf("in token\n");
			free(token->map[i++]);
		}
		//ft_strdel(token->map);
	}
}

int	error(char **str, char *msg)
{
	if (str)
		ft_strdel(str);
	ft_putendl_fd(msg, 2);
	return (0);
}

int	init(t_game *game, t_token *token)
{
	ft_bzero(game, sizeof(*game));
	ft_bzero(token, sizeof(*token));
	if (!get_player(game))
		return (0);
	return (1);
}

static void	print_coor(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int	main(void)
{
	t_game game;
	t_token token;

	if (!init(&game, &token))
	{
		fprintf(stderr, "error initializing data\n");
		return (0);
	}
	while (!game.ended)
	{
		if (!read_data(&game, &token))
		{
			freeall(&game, &token);
			return (0);
		}
		// if (game.ended)
		// 	break ;
		if (try_solve(&game, &token))
			print_coor(game.result.y, game.result.x);
		else
			break ;
	}
	freeall(&game, &token);
	print_coor(0, 0);
	return (0);
}
