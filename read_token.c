/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:41:18 by akilk             #+#    #+#             */
/*   Updated: 2022/06/30 10:40:14 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	get_token_size(t_token *token, char *line)
{
	if (!ft_strstr(line, "Piece"))
		return (error(NULL, "Failed to find token size in get_token_size()"));
	token->height = ft_atoi(ft_strchr(line, ' '));
	token->width = ft_atoi(ft_strrchr(line, ' '));
	if (!token->height || !token->width)
		return (error(NULL, "Error, invalid board size in get_token_size()"));
	return (1);
}

int	fill_token(t_token *token, char **line)
{
	int	i;

	i = 0;
	while (i < token->height)
	{
		get_next_line(0, line);
		ft_memcpy(token->map[i], *line, token->width);
		if (!token->map[i])
			return(error(token->map, "Error allocating token->map in fill_token()"));
		if (!validate_line(token->width,token->map[i], ".*"))
			return (error(token->map, "Error validating map in fill_token()"));
		printf("%s\n", token->map[i]);
		i++;
	}
	return (1);
}

int	get_shape(t_token *token)
{
	int		w;
	int		h;
	char	c;

	h = 0;
	token->start.x = token->width;
	token->start.y = token->height;
	while (h < token->height)
	{
		w = 0;
		while (w < token->width)
		{
			c = token->map[h][w];
			if (c == '*')
			{
				token->start.x = ft_min(w, token->start.x);
				token->end.x = ft_max(w, token->end.x);
				token->start.y = ft_min(h, token->start.y);
				token->end.y = ft_max(h, token->end.y);
			}
			w++;
		}
		h++;
	}
	token->dims.x = token->end.x - token->start.x + 1;
	token->dims.y = token->end.y - token->start.y + 1;
	return (1);
}

int	read_token(t_token *token, char **line)
{
	if (!get_token_size(token, *line))
		return(error(NULL, "Error getting token size in read_token()"));
	token->map = (char **)ft_memalloc(sizeof (char *) * (token->height + 1));
	if (!token->map)
		return(error(NULL, "Error allocating board in read_token()"));
	if (!make_map(token->map, token->height, token->width))
		return (error(line, "Error creating board in read_token()"));
	if (!fill_token(token, line))
		return (error (line, "Error filling board in read_token()"));
	if (!get_shape(token))
		return (error (line, "Error getting shape in read_token()"));
	return (1);
}
