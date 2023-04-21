/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:06:11 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/20 21:20:27 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	open_file_map(char *file_map, t_minirt *minirt)
{
	minirt->fd = open(file_map, O_RDONLY);
	if (minirt->fd < 0)
		error_manager(minirt, "Error: error in opening FD", RED);
}

void	get_size(char *file_map, t_minirt *minirt)
{
	minirt->fd = open(file_map, O_RDONLY);
	if (minirt->fd< 0)
		error_manager(minirt, "Error: error in opening FD", RED);
	minirt->rt_map.n_lines = get_n_lines(minirt->fd);
	if (close(minirt->fd) < 0)
		error_manager(minirt, "Error: error in closing FD", RED);
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
