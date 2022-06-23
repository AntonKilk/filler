/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:53 by akilk             #+#    #+#             */
/*   Updated: 2022/06/23 07:33:46 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Read the map
map structure:
int width
int height


 */

#include "ft_filler.h"

t_map	*read_map(int fd)
{

	t_map	*map;
	char	**data;
	char	*row;
	int		ret;
	int		i = 0;
	//malloc data

	map = (t_map *)malloc(sizeof(t_map));
	row = NULL;
	ret = get_next_line(fd, &row);
	map->width = ft_strlen(row);
	while (ret)
	{
		data[i] = ft_strdup(row);
		ret = get_next_line(fd, &row);
		i++;
	}
	map->height = i;
	printf("h: %d\n", map->height);
	printf("w: %d\n", map->width);
	map->data = data;
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
	{
		printf("usage: ./filler source_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	// error if !fd
	map = read_map(fd);
	int i = 0;
	while(i < map->height)
	{
		printf("%s\n", map->data[i]);
		i++;
	}
	// try_map(tetro_list);
	// free_list(tetro_list);
	return (0);
}
