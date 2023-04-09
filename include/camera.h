/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:52:10 by sasha             #+#    #+#             */
/*   Updated: 2023/04/09 16:54:44 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "world.h"
# include "parsing.h"
# include "scene.h"

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
bool	ft_solve_sph(t_sphere *sph, t_ray ray, double ret[2]);

/*	hit_cyl.c	*/
bool	ft_hit_cyl(t_cylinder cyl, t_ray ray, double dist_max, t_record *rec);
bool	ft_solve_cyl(t_cylinder cyl, t_ray ray, t_record temp[2]);
void	ft_copy_rec(t_record *rec, t_record *temp);

/*	hit_cyl_helper.c	*/
void		ft_inv_record(double inv[3][3], t_vec3 shift, t_record temp[2]);
void		ft_solve_cyl_top(t_cylinder cyl, t_ray ray, t_record *temp);
bool		ft_solve_cyl_body(t_cylinder cyl, t_ray ray, t_record rec[2]);
t_cylinder	ft_new_cyl(t_cylinder *cyl, double matrix[3][3]);
t_ray		ft_new_ray(t_ray *ray, double matrix[3][3], t_vec3 shift);

/*	ray_op.c	*/
t_vec3	ft_ray_at(t_ray ray, double t);

/*	ft_camera_ray.c	*/
t_ray	ft_camera_ray(t_canvas *canvas, int x, int y);


#endif