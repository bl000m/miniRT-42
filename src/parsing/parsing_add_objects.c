/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_add_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:35:05 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 13:06:48 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	add_new_plane_object(t_minirt *minirt, t_plane *new_object_content)
{
	t_object	*temp;
	t_object	*new_object;

	if (!new_object_content)
		return ;
	temp = minirt->scene->objects;
	while (temp->next)
		temp = temp->next;
	if (!temp->first)
	{
		temp->plane = new_object_content;
		temp->type = 'p';
		temp->first = 1;
	}
	else
	{
		new_object = calloc(sizeof(*new_object), 1);
		if (new_object == NULL)
			return ;
		new_object->plane = new_object_content;
		new_object->first = 1;
		new_object->next = NULL;
		new_object->type = 'p';
		temp->next = new_object;
	}
}

void	add_new_sphere_object(t_minirt *minirt, t_sphere *new_object_content)
{
	t_object	*temp;
	t_object	*new_object;

	if (!new_object_content)
		return ;
	temp = minirt->scene->objects;
	while (temp->next)
		temp = temp->next;
	if (!temp->first)
	{
		temp->sphere = new_object_content;
		temp->type = 's';
		temp->first = 1;
	}
	else
	{
		new_object = calloc(sizeof(*new_object), 1);
		if (new_object == NULL)
			return ;
		new_object->sphere = new_object_content;
		new_object->first = 1;
		new_object->type = 's';
		new_object->next = NULL;
		temp->next = new_object;
	}
}

void	add_new_cylinder(t_minirt *minirt, t_cyl *new_object_content)
{
	t_object	*temp;
	t_object	*new_object;

	if (!new_object_content)
		return ;
	temp = minirt->scene->objects;
	while (temp->next)
		temp = temp->next;
	if (!temp->first)
	{
		temp->cylinder = new_object_content;
		temp->type = 'c';
		temp->first = 1;
	}
	else
	{
		new_object = calloc(sizeof(*new_object), 1);
		if (new_object == NULL)
			return ;
		new_object->cylinder = new_object_content;
		new_object->first = 1;
		new_object->type = 'c';
		new_object->next = NULL;
		temp->next = new_object;
	}
}
