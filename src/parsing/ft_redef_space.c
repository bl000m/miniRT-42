/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redef_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:59:49 by hsliu             #+#    #+#             */
/*   Updated: 2023/04/24 15:56:25 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "scene.h"

static void	ft_new_pos(t_object *temp, double matrix[3][3], t_vec3 shift)
{
	if (temp->type == 's')
	{
		temp->sphere->center = \
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
		ft_matrix_mul(matrix, temp->plane->dir);
	}
}

static void	ft_init_canvas(t_minirt *minirt)
{
	double		fov;
	double		focal_len;
	t_canvas	*canvas;

	fov = (double)minirt->scene->camera.fov;
	if (fov <= 0)
		fov = 0.0001;
	else if (fov >= 180)
		fov = 179.9999;
	fov = (fov / 2) * (3.14159 / 180);
	focal_len = (WIDTH / 2) * (cos(fov) / sin(fov));
	canvas = &(minirt->canvas);
	canvas->eps = 0.01;
	canvas->pos.y = (HEIGHT / 2) * canvas->eps * -1;
	canvas->pos.z = focal_len * canvas->eps * -1;
	canvas->pos.x = (WIDTH / 2) * canvas->eps * -1;
}

void	ft_redef_space(t_minirt	*minirt)
{
	double		matrix[3][3];
	double		inv[3][3];
	t_vec3		shift;
	t_object	*temp;

	(void) inv;
	ft_rotate_xyz(ft_mul(minirt->scene->camera.orientation, -1), matrix, inv);
	shift = minirt->scene->camera.view_point;
	temp = minirt->scene->objects;
	while (temp)
	{
		ft_new_pos(temp, matrix, shift);
		temp = temp->next;
	}
	minirt->scene->light.pos = \
		ft_matrix_mul(matrix, ft_sub(minirt->scene->light.pos, shift));
	ft_init_canvas(minirt);
}
