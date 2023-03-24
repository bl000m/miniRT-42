/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cyl_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:26:39 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/24 14:48:13 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
	if fail, return 1
	ray : A + tB
	cylinder: 
	solve t and keep the result in ret[2]
	t is not effected by change base
*/
int ft_solve_cyl(t_cylinder cyl, t_ray ray, double ret[2])
{
	double		matrix[3][3];
	
	if (ft_rotate_xyz(cyl.dir, matrix))
	{
		return (1);
	}
	ray = ft_new_ray(&ray, matrix, cyl.center);
	cyl = ft_new_cyl(&cyl, matrix);
	//solve the new cyl / ray
	// hit body
	// hit top hit bottom
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