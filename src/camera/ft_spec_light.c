/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:11:36 by sasha             #+#    #+#             */
/*   Updated: 2023/04/20 15:29:26 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "exec.h"
#include "parsing.h"
#include "scene.h"
#include "world.h"

t_vec3	ft_mix_light(t_minirt *minirt, t_record *rec)
{
	t_vec3	color;
	
	color = ft_ambient_light(minirt, rec);
	color = ft_add(color, ft_diffuse_light(minirt, rec));
	color = ft_add(color, ft_spec_light(minirt, rec));
	return (ft_fix_overflow(color));
}

t_vec3	ft_fix_overflow(t_vec3 color)
{
	double	max;
	
	max = ft_max(color.x, color.y);
	max = ft_max(max, color.z);
	if (max < 255)
	{
		return (color);
	}
	color.x = (color.x / max) * 255;
	color.y = (color.y / max) * 255;
	color.z = (color.z / max) * 255;
	return (color);
}


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
	t_light		*light;
	t_ray		to_light;
	t_record	temp;

	light = &(minirt->scene->light);
	to_light = ft_init_ray(rec->pos, ft_unit_vec(ft_sub(light->pos, rec->pos)));
	if (ft_hit(minirt->scene->objects, to_light, &(temp)))
	{
		if (temp.dist <= ft_veclen(ft_sub(light->pos, rec->pos)))
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


