/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:53 by akilk             #+#    #+#             */
/*   Updated: 2022/06/27 16:48:45 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

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
	get_board_size(&game);
	read_board(&game);
	get_token_size(&token);
	printf("me: %c\n", game.me);
	printf("enemy: %c\n", game.enemy);
	printf("height: %d\n", game.height);
	printf("width: %d\n", game.width);
	printf("token height: %d\n", token.height);
	printf("token width: %d\n", token.width);

	return (0);
}
