/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:36:05 by mathia            #+#    #+#             */
/*   Updated: 2023/04/20 20:35:58 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "world.h"

int	initialize_plane(t_minirt *minirt, char **tokens)
{
	int	error;
	t_plane	*new_plane;

	error = 0;
	new_plane = ft_calloc(sizeof(*new_plane), 1);
	if (new_plane == NULL)
		return (1);
	new_plane->pos = get_instruction(tokens, 1, minirt);
	new_plane->dir = get_instruction(tokens, 2, minirt);
	error = check_parameters(new_plane->dir);
	if (error)
		error_manager(minirt, "Error: plane direction can't be 0,0,0", INFO);
	new_plane->color = get_instruction(tokens, 3, minirt);
	add_new_plane_object(minirt, new_plane);
	return (error);
}

int	initialize_sphere(t_minirt *minirt, char **tokens)
{
	int	error;
	t_sphere	*new_sphere;

	error = 0;
	new_sphere = ft_calloc(sizeof(*new_sphere), 1);
	if (new_sphere == NULL)
		return (1);
	new_sphere->center = get_instruction(tokens, 1, minirt);
	new_sphere->diameter = get_instruction_double(tokens, 2, minirt);
	new_sphere->color = get_instruction(tokens, 3, minirt);
	add_new_sphere_object(minirt, new_sphere);
	return (error);
}

int	initialize_cylinder(t_minirt *minirt, char **tokens)
{
	int	error;
	t_cylinder	*new_cylinder;

	error = 0;
	new_cylinder = ft_calloc(sizeof(*new_cylinder), 1);
	if (new_cylinder == NULL)
		return (1);
	new_cylinder->center = get_instruction(tokens, 1, minirt);
	new_cylinder->dir = get_instruction(tokens, 2, minirt);
	error = check_parameters(new_cylinder->dir);
	if (error)
		error_manager(minirt, "Error: cylinder direction can't be 0,0,0", INFO);
	new_cylinder->diameter = get_instruction_double(tokens, 3, minirt);
	new_cylinder->height = get_instruction_double(tokens, 4, minirt);
	new_cylinder->color = get_instruction(tokens, 5, minirt);
	add_new_cylinder_object(minirt, new_cylinder);
	return (error);
}

int	initialize_ambient_light(t_minirt *minirt, char **tokens)
{
	int	error;
	t_ambient	ambient_light;

	error = 0;
	ambient_light.ratio = get_instruction_double(tokens, 1, minirt);
	if (ambient_light.ratio < 0 || ambient_light.ratio > 1)
		error_manager(minirt, "Error: ratio must be between 0 and 1", RED);
	ambient_light.color = get_instruction(tokens, 2, minirt);
	minirt->scene->ambient_light = ambient_light;
	return (error);
}

int	initialize_camera(t_minirt *minirt, char **tokens)
{
	int	error;
	t_camera	camera;

	error = 0;
	camera.view_point = get_instruction(tokens, 1, minirt);
	camera.orientation = get_instruction(tokens, 2, minirt);
	error = check_parameters(camera.orientation);
	if (error)
		error_manager(minirt, "Error: Camera orientation can't be 0,0,0", INFO);
	camera.FOV = get_instruction_double(tokens, 3, minirt);
	if (camera.FOV >= 180)
		error_manager(minirt, "Error: Camera fov can't be higher than 179", RED);
	minirt->scene->camera = camera;
	return (error);
}

int	initialize_light(t_minirt *minirt, char **tokens)
{
	int	error;
	t_light	light;

	error = 0;
	light.pos = get_instruction(tokens, 1, minirt);
	light.ratio = get_instruction_double(tokens, 2, minirt);
	if (light.ratio < 0 || light.ratio > 1)
		error_manager(minirt, "Error: ratio must be between 0 and 1", RED);
	light.color = get_instruction(tokens, 3, minirt);
	minirt->scene->light = light;
	return (error);
}
