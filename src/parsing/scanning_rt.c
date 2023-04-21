/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:06:11 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 15:57:54 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	open_file_map(char *file_map, t_minirt *minirt)
{
	minirt->fd = open(file_map, O_RDONLY);
	if (minirt->fd < 0)
		error_manager(minirt, "Error: error in opening FD", RED);
}

void	closing_fd(t_minirt *minirt)
{
	if (close(minirt->fd) < 0)
		error_manager(minirt, "Error: error in closing FD", RED);
}

void	get_size(char *file_map, t_minirt *minirt)
{
	int		whitespaces;

	whitespaces = 0;
	minirt->fd = open(file_map, O_RDONLY);
	if (minirt->fd < 0)
		error_manager(minirt, "Error: error in opening FD", RED);
	minirt->rt_map.n_lines = get_n_lines(minirt, &whitespaces);
	if (minirt->rt_map.n_lines == whitespaces)
		error_manager(minirt, "Error: an empty file is not good !", RED);
	if (close(minirt->fd) < 0)
		error_manager(minirt, "Error: error in closing FD", RED);
	if (minirt->rt_map.n_lines == 0)
		error_manager(minirt, "Error: an empty file is not good !", RED);
}

int	check_whitespaces(char *line)
{
	int	i;
	int	size;
	int	whitespaces;

	whitespaces = 0;
	size = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (line[i] > 9 && line[i] < 13)
			whitespaces += 1;
		i++;
	}
	if (size == whitespaces)
		return (1);
	return (0);
}

int	get_n_lines(t_minirt *minirt, int *whitespaces)
{
	int		n_lines;
	char	*line;
	int		al_p;
	int		l_p;
	int		c_p;

	al_p = 0;
	l_p = 0;
	c_p = 0;
	n_lines = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(minirt->fd);
		if (!line)
			break ;
		if (line[0] == '\n' || check_whitespaces(line))
			*whitespaces += 1;
		check_scene_elem(line, &al_p, &c_p, &l_p);
		free(line);
		n_lines++;
	}
	manage_scene_err(minirt, al_p, c_p, l_p);
	return (n_lines);
}
