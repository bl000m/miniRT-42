/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:06:11 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/07 18:15:58 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	open_file_map(char *file_map)
{
	int		fd;

	fd = open(file_map, O_RDONLY);
	// check_fd_error(fd);
	return (fd);
}

void	get_size(char *file_map, t_minirt *minirt)
{
	int	fd;

	fd = open_file_map(file_map);
	minirt->rt_map->n_lines = get_n_lines(fd);
	close(fd);
}

int	get_n_lines(int fd)
{
	int		n_lines;
	char	*line;

	n_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (!line)
			break ;
		n_lines++;
	}
	return (n_lines);
}
