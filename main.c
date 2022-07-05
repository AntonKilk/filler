/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:53 by akilk             #+#    #+#             */
/*   Updated: 2022/07/04 09:42:25 by akilk            ###   ########.fr       */
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

int	init(t_game *game, t_token *token)
{
	ft_bzero(game, sizeof(*game));
	ft_bzero(token, sizeof(*token));
	get_player(game);
	return (1);
}

int	main(void)
{
	t_game game;
	t_token token;

	init(&game, &token);
	read_data(&game, &token);
	try_solve(&game, &token);
	// printf("me: %c\n", game.me);
	// printf("enemy: %c\n", game.enemy);
	// printf("height: %d\n", game.height);
	// printf("width: %d\n", game.width);
	// printf("token height: %d\n", token.height);
	// printf("token width: %d\n", token.width);
	printf("t start: w, h: %d, %d\n", token.start.x, token.start.y);
	printf("t end: w, h: %d, %d\n",token.end.x, token.end.y);
	printf("b start: w, h: %d, %d\n", game.start.x, game.start.y);
	printf("b end: w, h: %d, %d\n",game.end.x, game.end.y);
	return (0);
}
