/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:52:10 by sasha             #+#    #+#             */
/*   Updated: 2023/03/27 13:49:30 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "world.h"
# include "parsing.h"

typedef struct s_canvas	t_canvas;

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

/*	ray_op.c	*/
t_vec3	ft_ray_at(t_ray ray, double t);

/*	ft_camera_ray.c	*/
t_ray	ft_camera_ray(t_canvas *canvas, int x, int y);

#endif