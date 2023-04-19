/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:36:05 by mathia            #+#    #+#             */
/*   Updated: 2023/04/19 21:56:44 by mathia           ###   ########.fr       */
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
	new_plane->pos = get_instruction(tokens, 1);
	new_plane->dir = get_instruction(tokens, 2);
	error = check_parameters(new_plane->dir);
	if (error)
		alert("Input error: Plane direction can't be 0,0,0", INFO);
	new_plane->color = get_instruction(tokens, 3);
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
	new_sphere->center = get_instruction(tokens, 1);
	new_sphere->diameter = get_instruction_double(tokens, 2);
	new_sphere->color = get_instruction(tokens, 3);
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
	new_cylinder->center = get_instruction(tokens, 1);
	new_cylinder->dir = get_instruction(tokens, 2);
	error = check_parameters(new_cylinder->dir);
	if (error)
		alert("Input error: Cylinder direction can't be 0,0,0", INFO);
	new_cylinder->diameter = get_instruction_double(tokens, 3);
	new_cylinder->height = get_instruction_double(tokens, 4);
	new_cylinder->color = get_instruction(tokens, 5);
	add_new_cylinder_object(minirt, new_cylinder);
	return (error);
}

int	initialize_ambient_light(t_minirt *minirt, char **tokens)
{
	int	error;
	t_ambient	ambient_light;

	error = 0;
	// ambient_light = ft_calloc(sizeof(*ambient_light), 1);
	// if (ambient_light == NULL)
	// 	return (1);
	ambient_light.ratio = get_instruction_double(tokens, 1);
	ambient_light.color = get_instruction(tokens, 2);
	minirt->scene->ambient_light = ambient_light;
	return (error);
}

int	initialize_camera(t_minirt *minirt, char **tokens)
{
	int	error;
	t_camera	camera;

	error = 0;
	// camera = ft_calloc(sizeof(*camera), 1);
	// if (camera == NULL)
	// 	return (1);
	// printf("camera instr 1 = %s\n", tokens[1]);
	// printf("camera instr 2 = %s\n", tokens[2]);
	// printf("camera instr 3 = %s\n", tokens[3]);
	camera.view_point = get_instruction(tokens, 1);
	camera.orientation = get_instruction(tokens, 2);
	error = check_parameters(camera.orientation);
	if (error)
		alert("Input error: Camera orientation can't be 0,0,0", INFO);
	camera.FOV = get_instruction_double(tokens, 3);
	printf("camera pov x = %f, y= %f, z = %f\n", camera.view_point.x, camera.view_point.y, camera.view_point.z);
	printf("camera orientation x = %f, y= %f, z = %f\n", camera.orientation.x, camera.orientation.y, camera.orientation.z);

	minirt->scene->camera = camera;
	// printf("camera orientation z = %f\n", camera.orientation.z);
	return (error);
}

int	initialize_light(t_minirt *minirt, char **tokens)
{
	int	error;
	t_light	light;

	error = 0;
	// light = ft_calloc(sizeof(*light), 1);
	// if (light == NULL)
	// 	return (1);
	light.pos = get_instruction(tokens, 1);
	light.ratio = get_instruction_double(tokens, 2);
	light.color = get_instruction(tokens, 3);
	minirt->scene->light = light;
	return (error);
}
