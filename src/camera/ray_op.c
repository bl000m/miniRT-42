/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:32:21 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 15:36:04 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_vec3	ft_ray_at(t_ray ray, double t)
{
	t_vec3	temp;

	temp = ft_mul(ray.dir, t);
	temp = ft_add(temp, ray.orig);
	return (temp); 
}