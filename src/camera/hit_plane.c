/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:47:47 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/11 19:09:03 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include "scene.h"

/*
	check if minirt->ray.orig is the ray position
	if the line connecting the point touched by ray and a known point of the plane
	is dot_product ? 0 (œ epsilon that is distance btw 2 pixels) that means that we found the plane (except for the plane being parallel
	to ray => that would mean that ray never touch plane)
	The fabs() function calculates the absolute value of the floating-point argument x.
*/ 
bool	ft_hit_plane(t_minirt *minirt, t_plane *plane)
{
	double	scalar_magnitude;
	double	value;

	scalar_magnitude = ft_dot(minirt->ray.dir, plane->dir);
	if (fabs(scalar_magnitude) > 0)
	{
		value = ft_dot(ft_sub(plane->pos, minirt->ray.orig), plane->dir) / scalar_magnitude;
		// printf("\t/\t%.2f\t%.2f", value, minirt->rec.dist);
		if (value > minirt->canvas.eps && value < minirt->rec.dist)
		{
			// printf("HERE\n");
			minirt->rec.normal = ft_unit_vec(plane->dir);
			minirt->rec.pos = ft_add(minirt->ray.orig, ft_mul(minirt->ray.dir, value));
			minirt->rec.pos = ft_add(minirt->rec.pos, ft_mul(minirt->rec.normal, minirt->canvas.eps));
			minirt->rec.dist = value;
			minirt->rec.color = plane->color;
			// printf("\t%.2f", minirt->rec.dist);
			return (TRUE);
		}
	}
	return (FALSE);
}
