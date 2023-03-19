/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:52:10 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 17:22:09 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "world.h"

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
	double	t;
	t_vec3	p;
	t_vec3	normal;
	//color
}	t_record;

/*	hit_sphere.c	*/
int		ft_hit_sph(t_sphere *sph, t_ray ray, double root_max, t_record *rec);
void	ft_set_rec(double root, t_ray ray, t_record *rec);
int		ft_solve_sph(t_sphere *sph, t_ray ray, double *ret);

#endif