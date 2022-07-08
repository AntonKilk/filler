/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:53 by akilk             #+#    #+#             */
/*   Updated: 2022/07/08 22:29:11 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	error(char **str, char *msg)
{
	if (str)
		ft_strdel(str);
	ft_putendl_fd(msg, 2);
	return (0);
}

int	init(t_game *game, t_token *token, t_coords *result)
{
	ft_bzero(game, sizeof(*game));
	ft_bzero(token, sizeof(*token));
	ft_bzero(result, sizeof(*result));
	if (!get_player(game))
		return (0);
	return (1);
}

int	main(void)
{
	t_game game;
	t_token token;
	t_coords result;

	if (!init(&game, &token, &result))
	{
		fprintf(stderr, "error initializing data\n");
		return (0);
	}
	while (!game.ended)
	{
		fprintf(stderr, "in main line %d\n", __LINE__);
		if (!read_data(&game, &token))
		{
			fprintf(stderr, "main! line %d\n", __LINE__);
			return (0);
		}
		if (try_solve(&game, &token, &result))
		{
			printf("%d %d\n", result.y, result.x);
			fprintf(stderr, "%d %d\n", result.y, result.x);
		}
		else
			break ;
	}
	//clean map and token
	printf("0 0\n");
	fprintf(stderr, "finished\n");
	return (0);
}

// int i = 0;
// 		int countme = 0;
// 		int count_enemy = 0;
// 		while (i < game.height)
// 		{
// 			int j = 0;
// 			while (j < game.width)
// 			{
// 				if (ft_toupper(game.board[i][j]) == game.me)
// 					countme++;
// 				if (ft_toupper(game.board[i][j]) == game.enemy)
// 					count_enemy++;
// 				j++;
// 			}
// 			i++;
// 		}
// 		fprintf(stderr, "%d\n", count_enemy);
// 		fprintf(stderr, "Player %c have %d cells, got token with %d cells, expecting %d cells next turn\n", game.me, countme, token.amount, countme+token.amount-1);
