/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:01:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/07 18:20:54 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"

void	read_rt_map(char *source, t_minirt *minirt)
{
	int		fd;
	char	*line;
	int		n_line;

	n_line = 0;
	get_size(source, minirt);
	fd = open_file_map(source);
	while (n_line < minirt->rt_map->n_lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (close(fd) < 0)
		printf("need to set error\n");
}
