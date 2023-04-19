/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambient_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:46:14 by sasha             #+#    #+#             */
/*   Updated: 2023/04/19 22:04:56 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "exec.h"
#include "parsing.h"
#include "scene.h"
#include "world.h"

/*
	does not modify rec, only read from it
*/
t_vec3	ft_ambient_light(t_minirt *minirt, t_record *rec)
{
	t_ambient	*amb;
	t_vec3		color;
	
	amb = minirt->scene->ambient_light;
	color.x = amb->color.x * (rec->color.x / 255) * amb->ratio;
	color.y = amb->color.y * (rec->color.y / 255) * amb->ratio;
	color.z = amb->color.z * (rec->color.z / 255) * amb->ratio;
	return (color);
}
