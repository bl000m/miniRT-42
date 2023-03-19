/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:01 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 14:20:34 by sasha            ###   ########.fr       */
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

t_vec3	ft_rev_vec(t_vec3 v)
{
	t_vec3	temp;

	temp.x = -v.x;
	temp.y = -v.y;
	temp.z = -v.z;
	return (temp);
}
