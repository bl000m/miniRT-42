/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_something.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:39 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 16:16:07 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
	sph : (x - c1)^2 + (y - c2)^2 + (z - c3)^2 = r^2
	ray : orig + dir * t
	solve t
	if t is not btw t_min / t_max, return 0 (no hit)
	else if hit, save the hit record in *rec, and return 1
*/
int	ft_hit_sphere(t_sphere *sph, t_ray ray, double t_max, t_record *rec)
{
	
}