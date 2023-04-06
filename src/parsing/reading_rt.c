/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:01:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/06 16:49:42 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"

void	read_rt_map(char *source, t_minirt s_minirt)
{
	t_minirt	**values;
	int		y;

	values = NULL;
	y = 0;
	get_size(file_map, global);
	values = malloc(sizeof(t_minirt *) * (global->y_max + 1));
	if (!values)
		return (NULL);
	set_default(global);
	while (y < global->y_max)
	{
		values[y] = malloc(sizeof(t_minirt) * (global->x_max + 1));
		if (!values[y])
		{
			free_all(values);
			return (NULL);
		}
		y++;
	}
	create_list(file_map, global, values);
	return (values);
}

void	create_list(char *file_map, t_global *global, t_minirt **values)
{
	char	*line;
	int		fd;
	int		y;

	fd = 0;
	y = 0;
	global->y_max = get_values(file_map, 'y');
	fd = open_file_map(file_map);
	while (y < global->y_max)
	{
		line = get_next_line(fd);
		ft_printf("line = %s\n", line);
		if (line == NULL)
			break ;
		get_points(line, y, values);
		free(line);
		y++;
	}
	values[y] = NULL;
	close(fd);
}

}
