/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cyl_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:26:39 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/26 19:23:50 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
	if fail, return 1
	ray : A + tB
	cylinder: 
	solve t and keep the result in rec[2]
	t is not effected by change base
	the content of record has to be inverted back
*/
int ft_solve_cyl(t_cylinder cyl, t_ray ray, t_record temp[2])
{
	double		matrix[3][3];
	double		inv[3][3];
	t_vec3		shift;
	
	if (ft_rotate_xyz(cyl.dir, matrix, inv))
	{
		return (1);
	}
	shift = cyl.center;
	ray = ft_new_ray(&ray, matrix, shift);
	cyl = ft_new_cyl(&cyl, matrix);
	if (ft_solve_cyl_body(cyl, ray, temp))
	{
		return (1);
	}
	if (ft_dabs(temp[0].pos.z) > cyl.height / 2)
		//reset temp[0]
	if (ft_dabs(temp[1].pos.z) > cyl.height / 2)
		//reset temp[1]
	return (0);
}

/*
	the ray actually hit the top or bottom of the cyl
	solve the point where ray and the circle intersect
*/
void	ft_solve_cyl_top(t_cylinder cyl, t_ray ray, t_record *temp)
{
	if (temp.pos.z > 0)
		//intersect with the top
	else
		//intersect with the bottom
}

/*
	return 1 if there's no solution
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
		return (1);
	}
	discrim = sqrt(discrim);
	rec[0].dist = (-b - discrim) / (2.0 * a);
	rec[1].dist = (-b + discrim) / (2.0 * a);
	rec[0].pos = ft_ray_at(ray, rec[0].dist);
	rec[1].pos = ft_ray_at(ray, rec[1].dist);
	rec[0].normal = ft_unit_vec(rec[0].pos);
	rec[1].normal = ft_unit_vec(rec[0].pos);
	rec[0].color = cyl.color;
	rec[1].color = cyl.color;
	return (0);
}


/*
	change the base so that cyl is now upright along the z-axis
	with its center at (0, 0, 0)
*/
t_cylinder	ft_new_cyl(t_cylinder *cyl, double matrix[3][3])
{
	cyl->center = ft_vec(0, 0, 0);
	cyl->dir = ft_matrix_mul(matrix, cyl.dir);
	return (*cyl);
}

t_ray	ft_new_ray(t_ray *ray, double matrix[3][3], t_vec3 shift)
{	
	ray->orig = ft_sub(ray->orig, shift);
	ray->dir = ft_matrix_mul(matrix, ray->dir);
	return (*ray);
}