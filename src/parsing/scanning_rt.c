/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:06:11 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/19 21:31:31 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	open_file_map(char *file_map, t_minirt *minirt)
{
	int		fd;

	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		error_manager(minirt, "Error in opening FD", RED);
	return (fd);
}

void	get_size(char *file_map, t_minirt *minirt)
{
	int	fd;

	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		error_manager(minirt, "Error in opening FD", RED);
	minirt->rt_map.n_lines = get_n_lines(fd);
	if (close(fd) < 0)
		error_manager(minirt, "Error in closing FD", RED);
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
