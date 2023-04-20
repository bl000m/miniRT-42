/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:11:36 by sasha             #+#    #+#             */
/*   Updated: 2023/04/20 13:50:45 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "exec.h"
#include "parsing.h"
#include "scene.h"
#include "world.h"
/*
t_vec3	ft_diffuse_light(t_minirt *minirt, t_record *rec, t_vec3 ambient_spec_light)
{
	t_vec3	in;
	double	angle;
	t_vec3	mixed_light;

	in = minirt->ray.dir;
	angle = fabs(ft_dot(in, rec->normal));
	mixed_light = ft_vec(0, 0, 0);
	if (ft_in_shadow(minirt, rec))
	{
		return (mixed_light);
	}
	// printf("angle = %f\n", angle);
	if (angle)
	{
		mixed_light.x = ambient_spec_light.x * angle;
		mixed_light.y = ambient_spec_light.y * angle;
		mixed_light.z = ambient_spec_light.z * angle;
	}
	// diffuse_light.x = diffuse_light.x * ALBEDO;
	// diffuse_light.y = diffuse_light.y * ALBEDO;
	// diffuse_light.z = diffuse_light.z * ALBEDO;
	// mixed_light = ft_add(diffuse_light, *ambient_spec_light);
	// mixed_light = ft_mul(mixed_light, mixed_light);
	return (mixed_light);
}*/

t_vec3	ft_diffuse_light(t_minirt *minirt, t_record *rec)
{
	t_light	*light;
	t_vec3	to_light;
	t_vec3	normal;
	t_vec3	color;

	light = &(minirt->scene->light);
	to_light = ft_unit_vec(ft_sub(light->pos, rec->pos));
	normal = rec->normal;
	color = ft_vec(0, 0, 0);
	if (ft_in_shadow(minirt, rec))
	{
		return (color);
	}
	color.x = light->color.x * (rec->color.x / 255)\
				* light->ratio * ft_max(ft_dot(normal, to_light), 0);
	color.y = light->color.y * (rec->color.y / 255)\
				* light->ratio * ft_max(ft_dot(normal, to_light), 0);
	color.z = light->color.z * (rec->color.z / 255)\
				* light->ratio * ft_max(ft_dot(normal, to_light), 0);
	return (color);
}


bool	ft_in_shadow(t_minirt *minirt, t_record *rec)
{
	t_light		light;
	t_ray		to_light;
	t_record	temp;

	light = minirt->scene->light;
	to_light = ft_init_ray(rec->pos, ft_unit_vec(ft_sub(light.pos, rec->pos)));
	if (ft_hit(minirt->scene->objects, to_light, &(temp)))
	{
		return (TRUE);
	}
	return (FALSE);
}

t_vec3	ft_spec_light(t_minirt *minirt, t_record *rec)
{
	t_light	light;
	t_vec3	in;
	t_vec3	out;
	t_vec3	to_light;
	t_vec3	color;

	light = minirt->scene->light;
	in = minirt->ray.dir;
	out = ft_sub(in, ft_mul(rec->normal, 2 * ft_dot(in, rec->normal)));
	to_light = ft_unit_vec(ft_sub(light.pos, rec->pos));
	color = ft_vec(0, 0, 0);
	if (ft_in_shadow(minirt, rec))
	{
		return (color);
	}
	color.x = light.color.x * (rec->color.x / 255)\
				* light.ratio * pow(ft_max(ft_dot(out, to_light), 0), 3);
	color.y = light.color.y * (rec->color.y / 255)\
				* light.ratio * pow(ft_max(ft_dot(out, to_light), 0), 3);
	color.z = light.color.z * (rec->color.z / 255)\
				* light.ratio * pow(ft_max(ft_dot(out, to_light), 0), 3);
	return (color);
}


