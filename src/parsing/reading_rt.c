/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:01:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/19 21:39:25 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"

void	checking_identifier(t_minirt *minirt, char **tokens, int *error)
{
	if (ft_strncmp(tokens[0], "pl", 2) == 0)
		*error += initialize_plane(minirt, tokens);
	if (ft_strncmp(tokens[0], "sp", 2) == 0)
		*error += initialize_sphere(minirt, tokens);
	if (ft_strncmp(tokens[0], "cy", 2) == 0)
		*error += initialize_cylinder(minirt, tokens);
	if (ft_strncmp(tokens[0], "A", 1) == 0)
		*error += initialize_ambient_light(minirt, tokens);
	if (ft_strncmp(tokens[0], "C", 1) == 0)
		*error += initialize_camera(minirt, tokens);
	if (ft_strncmp(tokens[0], "L", 1) == 0)
		*error += initialize_light(minirt, tokens);
}

int	read_rt_map(char *source, t_minirt *minirt, int *error)
{
	int		fd;
	char	*line;
	int		n_line;
	char	**tokens;

	n_line = 0;
	get_size(source, minirt);
	fd = open_file_map(source, minirt);
	while (n_line < minirt->rt_map.n_lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		//printf("line = %s\n", line);
		tokens = ft_split(line, ' ');
		checking_identifier(minirt, tokens, error);
		ft_free(tokens);
		free(line);
		n_line++;
	}
	if (close(fd) < 0)
		error_manager(minirt, "Error in closing FD", RED);
	return (*error);
}

