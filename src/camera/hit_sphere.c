/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:39 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 17:21:16 by sasha            ###   ########.fr       */
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
		ft_set_rec(root[0], ray, rec);
		return (1);
	}
	else if (root[1] < root_max && root[1] > 0.001)
	{
		ft_set_rec(root[1], ray, rec);
		return (1);
	}
	return (0);
}

/*
	If the ray intersect the sphere from inside,
	the normal is reset, so it's always against the ray
*/
void	ft_set_rec(double root, t_ray ray, t_record *rec)
{
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = ft_div(ft_sub(rec.p, sph->center), sph->radius);
	if (ft_dot(ray, rec->normal) < 0)
	{
		rec->normal = ft_mul(rec->normal, -1);
	}
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
