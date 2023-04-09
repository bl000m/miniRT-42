/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:53:09 by hsliu             #+#    #+#             */
/*   Updated: 2023/04/09 18:45:00 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_vec3	ft_vec(double x, double y, double z)
{
	t_vec3	temp;

	temp.x = x;
	temp.y = y;
	temp.z = z;
	return (temp);
}

bool	ft_is_zero(t_vec3 v)
{
	if (v.x == 0 && v.y == 0 && v.z == 0)
	{
		return (1);
	}
	return (0);
}