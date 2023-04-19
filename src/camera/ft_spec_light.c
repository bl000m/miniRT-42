/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:11:36 by sasha             #+#    #+#             */
/*   Updated: 2023/04/19 22:44:30 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "exec.h"
#include "parsing.h"
#include "scene.h"
#include "world.h"

t_vec3	ft_spec_light(t_minirt *minirt, t_record *rec)
{
	t_light	*light;
	t_vec3	in;
	t_vec3	out;
	t_vec3	to_light;
	t_vec3	color;

	light = minirt->scene->light;
	in = minirt->ray.dir;
	out = ft_sub(in, ft_mul(rec->normal, 2 * ft_dot(in, rec->normal)));
	to_light = ft_unit_vec(ft_sub(light->pos, rec->pos));
	color.x = light->color.x * (rec->color.x / 255)\
				* light->ratio * pow(ft_max(ft_dot(out, to_light), 0), 3);
	color.y = light->color.y * (rec->color.y / 255)\
				* light->ratio * pow(ft_max(ft_dot(out, to_light), 0), 3);
	color.z = light->color.z * (rec->color.z / 255)\
				* light->ratio * pow(ft_max(ft_dot(out, to_light), 0), 3);
	return (color);
}


