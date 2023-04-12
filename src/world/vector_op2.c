/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:01 by sasha             #+#    #+#             */
/*   Updated: 2023/04/12 13:16:55 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

double	ft_squr_len(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	ft_veclen(t_vec3 v)
{
	return (sqrt(ft_squr_len(v)));
}

/*
	return the normalized vector
	if v == 0, return v
*/
t_vec3	ft_unit_vec(t_vec3 v)
{
	double	len;

	len = ft_veclen(v);
	if (len == 0)
	{
		return (v);
	}
	return (ft_div(v, len));
}

/* The dot product, also called scalar product,
is a measure of how closely two vectors align, in terms of the directions they point.
*/
double	ft_dot(t_vec3 v1, t_vec3 v2)
{
	double	temp;

	temp = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (temp);
}

t_vec3	ft_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	temp;

	temp.x = u.y * v.z - u.z * v.y;
	temp.y = u.z * v.x - u.x * v.z;
	temp.z = u.x * v.y - u.y * v.x;
	return (temp);
}
