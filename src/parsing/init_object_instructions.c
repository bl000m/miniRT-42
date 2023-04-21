/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_instructions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:28:53 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 16:44:18 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	initialize_plane(t_minirt *minirt, char **tokens, char *line)
{
	t_plane	*new_plane;
	int		error;

	error = 0;
	new_plane = ft_calloc(sizeof(*new_plane), 1);
	if (new_plane == NULL)
		return (1);
	new_plane->pos = get_instruction(tokens, 1, minirt, line);
	new_plane->dir = get_instruction(tokens, 2, minirt, line);
	error = check_parameters(new_plane->dir);
	if (error)
	{
		finish_gnl(minirt->fd);
		closing_fd(minirt);
		ft_free(tokens);
		free(line);
		free(new_plane);
		error_manager(minirt, "Error: plane direction can't be 0,0,0", INFO);
	}
	new_plane->color = get_instruction(tokens, 3, minirt, line);
	add_new_plane_object(minirt, new_plane);
	return (error);
}

int	initialize_sphere(t_minirt *minirt, char **tokens, char *line)
{
	int			error;
	t_sphere	*new_sphere;

	error = 0;
	new_sphere = ft_calloc(sizeof(*new_sphere), 1);
	if (new_sphere == NULL)
		return (1);
	add_new_sphere_object(minirt, new_sphere);
	new_sphere->center = get_instruction(tokens, 1, minirt, line);
	new_sphere->diameter = get_ins_double(tokens, 2, minirt, line);
	new_sphere->color = get_instruction(tokens, 3, minirt, line);
	return (error);
}

int	initialize_cylinder(t_minirt *minirt, char **tokens, char *line)
{
	int			error;
	t_cyl		*new_cylinder;

	error = 0;
	new_cylinder = ft_calloc(sizeof(*new_cylinder), 1);
	if (new_cylinder == NULL)
		return (1);
	add_new_cylinder(minirt, new_cylinder);
	new_cylinder->center = get_instruction(tokens, 1, minirt, line);
	new_cylinder->dir = get_instruction(tokens, 2, minirt, line);
	new_cylinder->diameter = get_ins_double(tokens, 3, minirt, line);
	new_cylinder->height = get_ins_double(tokens, 4, minirt, line);
	new_cylinder->color = get_instruction(tokens, 5, minirt, line);
	error = check_parameters(new_cylinder->dir);
	if (error)
	{
		finish_gnl(minirt->fd);
		closing_fd(minirt);
		ft_free(tokens);
		free(line);
		error_manager(minirt, "Error: cylinder direction can't be 0,0,0", INFO);
	}
	return (error);
}
