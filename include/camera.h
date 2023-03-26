/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:52:10 by sasha             #+#    #+#             */
/*   Updated: 2023/03/26 18:34:46 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "world.h"
# include "parsing.h"

/*
	pos is the lower left corner of the canvas
	eps stands for episilon, the distance btw pixel
*/
typedef struct s_canvas
{
	t_vec3	pos;
	double	eps;
}	t_canvas;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

typedef struct s_record
{
	double	dist;
	t_vec3	pos;
	t_vec3	normal;
	t_vec3	color;
}	t_record;

/*	hit_sphere.c	*/
bool	ft_hit_sph(t_sphere *sph, t_ray ray, double root_max, t_record *rec);
void	ft_set_rec_sph(double dist, t_sphere *sph, t_ray ray, t_record *rec);
bool	ft_solve_sph(t_sphere *sph, t_ray ray, double *ret);

#endif