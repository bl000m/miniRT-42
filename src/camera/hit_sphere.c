/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_something.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:39 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 17:05:30 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	ft_hit_sph(t_sphere *sph, t_ray ray, double root_max, t_record *rec)
{
	double	discrim;
	double	sqrt_dis;
	double	root[2];

	if (ft_solve_sph(sph, ray, root) == 0)
	{
		return (0);
	}
	if (root[0] < root_max && root[0] > 0.001)
	{
		rec->t = root[0];
		rec->p = ft_ray_at(ray, root[0]);
		rec->normal = ft_div(ft_sub(rec.p, sph->center), sph->radius);
		return (1);
	}
	else if (root[1] < root_max && root[1] > 0.001)
	{
		rec->t = root[1];
		rec->p = ft_ray_at(ray, root[1]);
		rec->normal = ft_div(ft_sub(rec.p, sph->center), sph->radius);
		return (1);
	}
	return (0);
}

/*
	sph : (x - c1)^2 + (y - c2)^2 + (z - c3)^2 = r^2
	ray : orig + dir * t
	solve t
	if t is not btw t_min / t_max, return 0 (no hit)
	else if hit, save the hit record in *rec, and return 1
*/
int	ft_solve_sph(t_sphere *sph, t_ray ray, double *ret)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discrim;

	oc = ft_sub(ray.orig - sph->center);
	a = ft_dot(ray.dir, ray.dir);
	b = 2 * ft_dot(oc, ray.dir);
	c = ft_dot(oc, oc) - sph->radius * sph->radius;
	discrim = b * b - 4 * a * c;
	if (discrim < 0)
	{
		return (0);
	}
	discrim = sqrt(discrim);
	ret[0] = (-b - discrim) / (2.0 * a);
	ret[1] = (-b + discrim) / (2.0 * a);
	return (1);
}
