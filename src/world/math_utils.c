/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:08:38 by sasha             #+#    #+#             */
/*   Updated: 2023/04/19 22:35:04 by sasha            ###   ########.fr       */
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