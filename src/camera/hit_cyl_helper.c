/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cyl_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:26:39 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/24 16:00:38 by sasha            ###   ########.fr       */
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
int ft_solve_cyl(t_cylinder cyl, t_ray ray, t_record rec[2])
{
	double		matrix[3][3];
	double		inv[3][3];
	t_vec3		shift;
	
	if (ft_rotate_xyz(cyl.dir, matrix))
	{
		return (1);
	}
	
	ray = ft_new_ray(&ray, matrix, cyl.center);
	cyl = ft_new_cyl(&cyl, matrix);
	/*
	solve the new cyl / ray
		hit_body
		 	get rec [0 1]
		if pos.z < cyl.height / 2
			update rec[0] with ft_hit_bottom
		if pos.z > cyl.hight / 2
			update rec[1] with ft_hit_top
	
	note : 
		shall I make the hit_record here ? 
		Do I only keep a ret ? (Only one is needed)
	return (0)
	*/
}




/*
	return 0 if there's no solution
*/
int	ft_solve_cyl_body(t_cylinder cyl, t_ray ray, double ret[2])
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
		return (0);
	}
	ret[0] = (-b - discrim) / (2.0 * a);
	ret[1] = (-b + discrim) / (2.0 * a);
	return (1);
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