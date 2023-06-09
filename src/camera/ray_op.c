/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:32:21 by sasha             #+#    #+#             */
/*   Updated: 2023/04/21 12:49:37 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	ft_ray_at(t_ray ray, double t)
{
	t_vec3	temp;

	temp = ft_mul(ray.dir, t);
	temp = ft_add(temp, ray.orig);
	return (temp);
}

t_ray	ft_init_ray(t_vec3 orig, t_vec3 dir)
{
	t_ray	temp;

	temp.orig = orig;
	temp.dir = dir;
	return (temp);
}
