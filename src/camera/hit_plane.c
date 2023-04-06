/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:47:47 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/06 15:52:09 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	ft_hit_plane(t_sphere *sph, t_ray ray, double dist_max, t_record *rec)
{
	// if the line connecting the point touched by ray and a known point of the plane
	// is dot_product = 0 that means that we found the plane (except for the plane being parallel
	// to ray => that would mean that ray never touch plane)
}


void	ft_new_plane(t_vec3 pos, t_vec3 dir, t_vec3 color)
{
	t_plane	plane;

	plane.pos =	ft_vec(0.0 ,0.0 ,0.0);
	plane.dir = ft_vec(0, 1.0, 0);
	plane.color = ft_vec(255, 0, 225);
}
