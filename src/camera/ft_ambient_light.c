/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambient_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:46:14 by sasha             #+#    #+#             */
/*   Updated: 2023/04/21 12:49:48 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "scene.h"
#include "world.h"

/*
	does not modify rec, only read from it
*/
t_vec3	ft_ambient_light(t_minirt *minirt, t_record *rec)
{
	t_ambient	amb;
	t_vec3		color;

	amb = minirt->scene->ambient_light;
	color.x = amb.color.x * (rec->color.x / 255) * amb.ratio;
	color.y = amb.color.y * (rec->color.y / 255) * amb.ratio;
	color.z = amb.color.z * (rec->color.z / 255) * amb.ratio;
	return (color);
}
