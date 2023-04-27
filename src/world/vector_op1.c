/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:51:57 by sasha             #+#    #+#             */
/*   Updated: 2023/04/27 11:02:15 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_vec3	ft_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	temp;

	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;
	temp.z = v1.z + v2.z;
	return (temp);
}

t_vec3	ft_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3	temp;

	temp.x = v1.x - v2.x;
	temp.y = v1.y - v2.y;
	temp.z = v1.z - v2.z;
	return (temp);
}

t_vec3	ft_mul(t_vec3 v1, double t)
{
	t_vec3	temp;

	temp.x = v1.x * t;
	temp.y = v1.y * t;
	temp.z = v1.z * t;
	return (temp);
}

t_vec3	ft_div(t_vec3 v1, double t)
{
	t_vec3	temp;

	temp.x = v1.x / t;
	temp.y = v1.y / t;
	temp.z = v1.z / t;
	return (temp);
}
