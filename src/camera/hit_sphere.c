/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:39 by sasha             #+#    #+#             */
/*   Updated: 2023/03/27 14:38:01 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	ft_hit_sph(t_sphere *sph, t_ray ray, double dist_max, t_record *rec)
{
	double	temp[2];

	if (!ft_solve_sph(sph, ray, temp))
	{
		return (FALSE);
	}
	if (temp[0] < dist_max && temp[0] > 0.001)
	{
		ft_set_rec_sph(temp[0], sph, ray, rec);
		return (TRUE);
	}
	else if (temp[1] < dist_max && temp[1] > 0.001)
	{
		ft_set_rec_sph(temp[1], sph, ray, rec);
		return (TRUE);
	}
	return (FALSE);
}

/*
	If the ray intersect the sphere from inside,
	the normal is reset, so it's always against the ray
*/
void	ft_set_rec_sph(double dist, t_sphere *sph, t_ray ray, t_record *rec)
{
	rec->dist = dist;
	rec->pos = ft_ray_at(ray, dist);
	rec->normal = ft_unit_vec(ft_sub(rec->pos, sph->center));
	if (ft_dot(ray.dir, rec->normal) < 0)
	{
		rec->normal = ft_mul(rec->normal, -1);
	}
	rec->color = sph->color;
}

/*
	return 0 when no solution
	
	sph : (x - c1)^2 + (y - c2)^2 + (z - c3)^2 = r^2
	ray : orig + dir * t
	solve t
	if t is not btw t_min / t_max, return 0 (no hit)
	else if hit, save the hit record in *rec, and return 0
*/
bool	ft_solve_sph(t_sphere *sph, t_ray ray, double ret[2])
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discrim;

	oc = ft_sub(ray.orig, sph->center);
	a = ft_dot(ray.dir, ray.dir);
	b = 2 * ft_dot(oc, ray.dir);
	c = ft_dot(oc, oc) - sph->radius * sph->radius;
	discrim = b * b - 4 * a * c;
	if (discrim < 0)
	{
		return (FALSE);
	}
	discrim = sqrt(discrim);
	ret[0] = (-b - discrim) / (2.0 * a);
	ret[1] = (-b + discrim) / (2.0 * a);
	return (TRUE);
}
