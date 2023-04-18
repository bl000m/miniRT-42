/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redef_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:59:49 by hsliu             #+#    #+#             */
/*   Updated: 2023/04/18 16:46:07 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "exec.h"
#include "parsing.h"
#include "scene.h"
#include "world.h"

static void	ft_new_pos(t_object *temp, double matrix[3][3], t_vec3 shift)
{
	if (temp->type == 's')
	{
		temp->sphere->center =\
		ft_matrix_mul(matrix, ft_sub(temp->sphere->center, shift));
	}
	else if (temp->type == 'c')
	{
		temp->cylinder->center = \
		ft_matrix_mul(matrix, ft_sub(temp->cylinder->center, shift));
		temp->cylinder->dir = \
		ft_matrix_mul(matrix, temp->cylinder->dir);
	}
	else if (temp->type == 'p')
	{
		temp->plane->pos = \
		ft_matrix_mul(matrix, ft_sub(temp->plane->pos, shift));
		temp->plane->dir = \
		ft_matrix_mul(matrix, temp->plane->pos);
	}
}

void	ft_redef_space(t_minirt	*minirt)
{
	double		matrix[3][3];
	double		inv[3][3];
	t_vec3		shift;
	t_object	*temp;

	(void)	inv;
	//printf("%f %f %f\n", minirt->scene->camera->orientation.x, minirt->scene->camera->orientation.y, minirt->scene->camera->orientation.z);
	ft_rotate_xyz(ft_mul(minirt->scene->camera->orientation, -1) , matrix, inv);
	shift = minirt->scene->camera->view_point;
	temp = minirt->scene->objects;
	while (temp)
	{
	//	printf("%f %f %f\n", minirt->scene->camera->orientation.x, minirt->scene->camera->orientation.y, minirt->scene->camera->orientation.z);
		ft_new_pos(temp, matrix, shift);
		temp = temp->next;
	}
	minirt->scene->light->pos = ft_matrix_mul(matrix, ft_sub(minirt->scene->light->pos, shift));
}