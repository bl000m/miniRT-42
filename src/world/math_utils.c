/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:08:38 by sasha             #+#    #+#             */
/*   Updated: 2023/04/21 13:05:23 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

double	ft_dabs(double x)
{
	if (x > 0)
	{
		return (x);
	}
	return (-x);
}

double	ft_max(double x, double y)
{
	if (x >= y)
	{
		return (x);
	}
	return (y);
}
