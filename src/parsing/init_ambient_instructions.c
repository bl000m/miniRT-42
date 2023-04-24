/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:36:05 by mathia            #+#    #+#             */
/*   Updated: 2023/04/24 15:11:11 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	initialize_ambient_light(t_minirt *minirt, char **tokens, char *line)
{
	int			error;
	t_ambient	ambient_light;

	error = 0;
	ambient_light.ratio = get_ins_double(tokens, 1, minirt, line);
	if (ambient_light.ratio < 0 || ambient_light.ratio > 1)
		message_exit("Error: Camera orientation can't be 0,0,0", \
					minirt, tokens, line);
	ambient_light.color = get_instruction(tokens, 2, minirt, line);
	if (ambient_light.color.x < 0 || ambient_light.color.x > 255
		|| ambient_light.color.y < 0 || ambient_light.color.y > 255
		|| ambient_light.color.z < 0 || ambient_light.color.z > 255)
		message_exit("Error: color must be btw 0 and 255", \
					minirt, tokens, line);
	minirt->scene->ambient_light = ambient_light;
	return (error);
}

int	initialize_camera(t_minirt *minirt, char **tokens, char *line)
{
	int			error;
	t_camera	camera;

	error = 0;
	camera.view_point = get_instruction(tokens, 1, minirt, line);
	camera.orientation = get_instruction(tokens, 2, minirt, line);
	error = check_parameters(camera.orientation);
	if (error)
		message_exit("Error: Camera orientation can't be 0,0,0", \
				minirt, tokens, line);
	camera.fov = get_ins_double(tokens, 3, minirt, line);
	if (camera.fov >= 180)
		error_manager(minirt, \
			"Error: Camera fov can't be higher than 179", RED);
	minirt->scene->camera = camera;
	return (error);
}

int	initialize_light(t_minirt *minirt, char **tokens, char *line)
{
	int		error;
	t_light	light;

	error = 0;
	light.pos = get_instruction(tokens, 1, minirt, line);
	light.ratio = get_ins_double(tokens, 2, minirt, line);
	if (light.ratio < 0 || light.ratio > 1)
		message_exit("Error: ratio must be between 0 and 1", \
					minirt, tokens, line);
	light.color = get_instruction(tokens, 3, minirt, line);
	if (light.color.x < 0 || light.color.x > 255
		|| light.color.y < 0 || light.color.y > 255
		|| light.color.z < 0 || light.color.z > 255)
		message_exit("Error: color must be btw 0 and 255", \
					minirt, tokens, line);
	minirt->scene->light = light;
	return (error);
}

void	finish_gnl(int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}
