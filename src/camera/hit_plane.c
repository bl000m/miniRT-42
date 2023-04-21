/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:47:47 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 13:02:22 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "exec.h"
#include "scene.h"

/*
	if align_difference = 0 ray and plane are parallel and 
	no intersection is possible
	The fabs() function calculates the absolute value of the
	floating-point argument x.
*/
bool	ft_hit_plane(t_plane *plane, t_ray ray, double dist_max, t_record *rec)
{
	double	align_difference;
	double	distance_to_plane;
	t_vec3	distance_origins;

	align_difference = ft_dot(ray.dir, plane->dir);
	if (align_difference == 0)
		return (FALSE);
	distance_origins = ft_sub(plane->pos, ray.orig);
	distance_to_plane = ft_dot(distance_origins, plane->dir) / align_difference;
	if (distance_to_plane > 0.00001 && distance_to_plane < dist_max)
	{
		rec->normal = ft_unit_vec(plane->dir);
		if (ft_dot(ray.dir, rec->normal) > 0)
		{
			rec->normal = ft_mul(rec->normal, -1);
		}
		rec->pos = ft_add(ray.orig, ft_mul(ray.dir, distance_to_plane));
		rec->dist = distance_to_plane;
		rec->color = plane->color;
		return (TRUE);
	}
	return (FALSE);
}
