/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cyl_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:26:39 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/29 13:39:07 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_inv_record(double inv[3][3], t_vec3 shift, t_record temp[2])
{
	if (temp[0].dist != -1)
	{
		temp[0].pos = ft_add(ft_matrix_mul(inv, temp[0].pos), shift);
		temp[0].normal = ft_matrix_mul(inv, temp[0].normal);
	}
	if (temp[1].dist != -1)
	{
		temp[1].pos = ft_matrix_mul(inv, ft_add(temp[1].pos, shift));
		temp[1].normal = ft_matrix_mul(inv, temp[1].normal);
	}
}

/*
	the ray actually hit the top or bottom of the cyl
	solve the point where ray and the circle intersect
*/
void	ft_solve_cyl_top(t_cylinder cyl, t_ray ray, t_record *temp)
{
	if (ft_dabs(temp->pos.z) <= cyl.height / 2)
	{
		return ;
	}
	if (temp->pos.z > 0)
	{
		temp->dist = (cyl.height / 2 - ray.orig.z) / ray.dir.z;
		temp->pos = ft_ray_at(ray, temp->dist);
		temp->normal = ft_vec(0, 0, 1);
	}
	else
	{
		temp->dist = (cyl.height / -2 - ray.orig.z) / ray.dir.z;
		temp->pos = ft_ray_at(ray, temp->dist);
		temp->normal = ft_vec(0, 0, -1);
	}
	if (temp->pos.x * temp->pos.x + temp->pos.y * temp->pos.y > cyl.diameter * cyl.diameter)
	{
		temp->dist = -1;
	}
}

/*
	return 0 if there's no solution
*/
bool	ft_solve_cyl_body(t_cylinder cyl, t_ray ray, t_record rec[2])
{
	double	a;
	double	b;
	double	c;
	double	discrim;
	
	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y;
	b = 2 * (ray.orig.x * ray.dir.x + ray.orig.y * ray.dir.y);
	c = ray.orig.x * ray.orig.x + ray.orig.y * ray.orig.y
		- cyl.diameter * cyl.diameter;
	discrim = b * b - 4 * a * c;
	if (discrim < 0)
	{
		return (FALSE);
	}
	discrim = sqrt(discrim);
	rec[0].dist = (-b - discrim) / (2.0 * a);
	rec[1].dist = (-b + discrim) / (2.0 * a);
	rec[0].pos = ft_ray_at(ray, rec[0].dist);
	rec[1].pos = ft_ray_at(ray, rec[1].dist);
	rec[0].normal = ft_unit_vec(rec[0].pos);
	rec[1].normal = ft_unit_vec(ft_mul(rec[0].pos, -1));
	rec[0].color = cyl.color;
	rec[1].color = cyl.color;
	return (TRUE);
}


/*
	change the base so that cyl is now upright along the z-axis
	with its center at (0, 0, 0)
*/
t_cylinder	ft_new_cyl(t_cylinder *cyl, double matrix[3][3])
{
	cyl->center = ft_vec(0, 0, 0);
	cyl->dir = ft_matrix_mul(matrix, cyl->dir);
	return (*cyl);
}

t_ray	ft_new_ray(t_ray *ray, double matrix[3][3], t_vec3 shift)
{	
	ray->orig = ft_matrix_mul(matrix, ft_sub(ray->orig, shift));
	ray->dir = ft_matrix_mul(matrix, ray->dir);
	return (*ray);
}