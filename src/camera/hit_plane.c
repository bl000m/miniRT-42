/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:47:47 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/13 12:15:00 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include "scene.h"

/*
	if align_difference = 0 ray and plane are parallel and no intersection is possible
	The fabs() function calculates the absolute value of the floating-point argument x.
*/
bool	ft_hit_plane(t_minirt *minirt, t_plane *plane)
{
	double	align_difference;
	double	distance_to_plane;
	t_vec3	distance_origins;

	align_difference = ft_dot(minirt->ray.dir, plane->dir);
	if (align_difference == 0)
		return (FALSE);
	distance_origins = ft_sub(plane->pos, minirt->ray.orig);
	distance_to_plane = ft_dot(distance_origins, plane->dir) / align_difference;
	// printf("\t/\t%.2f\t%.2f\n", distance_to_plane, minirt->rec.dist);
	if (distance_to_plane > 0.00001 || distance_to_plane < minirt->rec.dist)
	{
		// printf("HERE\n");
		minirt->rec.normal = ft_unit_vec(plane->dir);
		minirt->rec.pos = ft_add(minirt->ray.orig, ft_mul(minirt->ray.dir, distance_to_plane));
		minirt->rec.dist = distance_to_plane;
		//minirt->rec.color = plane->color;
		// printf("\t%.2f\n", minirt->rec.dist);
		return (TRUE);
	}
	return(FALSE);
}
