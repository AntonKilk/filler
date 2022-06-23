/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:48:27 by akilk             #+#    #+#             */
/*   Updated: 2022/06/23 07:19:53 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include <stdio.h> // clean
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
}				t_map;

/* main.c */
int		main(int argc, char **argv);


#endif
