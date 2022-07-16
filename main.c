/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:53 by akilk             #+#    #+#             */
/*   Updated: 2022/07/16 20:20:40 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	freeall(t_game *game, t_token *token)
{
	if (game->board)
		ft_free_tab(game->board, game->height);
	if (token->map)
		ft_free_tab(token->map, token->height);
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
		if (try_solve(&game, &token))
			print_coor(game.result.y, game.result.x);
		else
			break ;
	}
	freeall(&game, &token);
	print_coor(0, 0);
	return (0);
}
