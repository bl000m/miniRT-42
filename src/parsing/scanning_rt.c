/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:06:11 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/06 16:06:21 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	open_file_map(char *file_map)
{
	int		fd;

	fd = open(file_map, O_RDONLY);
	check_fd_error(fd);
	return (fd);
}

void	get_size(char *file_map, t_global *global)
{
	int		x_max;
	int		y_max;

	x_max = get_values(file_map, 'x');
	y_max = get_values(file_map, 'y');
	if (x_max == -1 || y_max == -1)
		return ;
	global->x_max = x_max;
	global->y_max = y_max;
}

int	get_values(char *file_map, char c)
{
	int	fd;

	fd = open_file_map(file_map);
	if (c == 'x')
		return (get_x_max(fd));
	else if (c == 'y')
		return (get_y_max(fd));
	else
		return (-1);
	close(fd);
}

int	get_x_max(int fd)
{
	int		x_max;
	char	*line;

	line = get_next_line(fd);
	x_max = ft_words(line, ' ');
	free(line);
	return (x_max);
}

int	get_y_max(int fd)
{
	int		y_max;
	char	*line;

	y_max = 0;
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (!line)
			break ;
		y_max++;
	}
	return (y_max);
}
