/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:11:05 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/15 16:07:50 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parsing.h"
# include "world.h"
# include "camera.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# define GREEN "\x1b[32m"
# define RED "\x1b[41m"
# define INFO "\x1b[35m"
# define NORMAL "\x1b[m"
typedef struct s_canvas	t_canvas;

// typedef struct s_rgb
// {
// 	uint8_t		r; // unsigned char = 1 byte. instead of 3 byte of a double or 2 of an int
// 	uint8_t		g;
// 	uint8_t		b;
// }	t_rgb;

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

typedef struct s_ambient
{
	double	ratio;
	t_vec3	color;
}	t_ambient;

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_vec3	color;
}	t_light;

typedef struct s_camera
{
	t_vec3		view_point;
	t_vec3		orientation;
	int			FOV;
}	t_camera;

typedef struct s_object
{
	t_plane			*plane;
	t_sphere		*sphere;
	t_cylinder		*cylinder;
	char			type;
	int				first;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	t_ambient	*ambient_light;
	t_camera	*camera;
	t_light		*light;
	t_object	*objects;
}	t_scene;

typedef struct s_image
{
	char	*buf;
	int		pixel_bit;
	int		line_byte;
	int		endian;
}	t_image;

/*
	pos is the lower left corner of the canvas
	eps stands for episilon, the distance btw pixel
*/
typedef struct s_canvas
{
	t_vec3	pos; // -(WIDTH / 2) * eps ; -(HEIGHT / 2) * eps ; -focal_length
	double	eps;
}	t_canvas;

typedef struct s_map
{
	int	n_lines;
}	t_map;

typedef struct s_minirt
{
	void		*mlx;
	void		*win;
	void		*img;
	t_image		img_info;
	t_canvas	canvas;
	t_node		*world;
	t_map		rt_map;
	t_scene		*scene;
	t_record	rec;
	t_ray		ray;
	int			x;
	int			y;
}	t_minirt;

int		read_rt_map(char *source, t_minirt *minirt, int *error);
int		open_file_map(char *file_map);
int		initialize_plane(t_minirt *minirt, char **tokens);
int		initialize_sphere(t_minirt *minirt, char **tokens);
int		initialize_cylinder(t_minirt *minirt, char **tokens);
int		initialize_ambient_light(t_minirt *minirt, char **tokens);
int		initialize_camera(t_minirt *minirt, char **tokens);
int		initialize_light(t_minirt *minirt, char **tokens);
void	get_size(char *file_map, t_minirt *minirt);
int		get_n_lines(int fd);
t_vec3	get_instruction(char **tokens, int index);
double	get_instruction_double(char **tokens, int index);
// t_rgb 	get_instruction_rgb(char **tokens, int index);
int		check_commas(char *token);
void	add_new_plane_object(t_minirt *minirt, t_plane *new_object_content);
void	add_new_sphere_object(t_minirt *minirt, t_sphere *new_object_content);
void	add_new_cylinder_object(t_minirt *minirt, t_cylinder *new_object_content);
void	ft_put_pixel(t_image *img_info, int x, int y, int color);
void	generating_camera_ray_draw(t_minirt *minirt, t_object *object);
int		check_parameters(t_vec3 vector);

/*	hit_plane.c	*/
bool	ft_hit_plane(t_plane *plane, t_ray ray, double dist_max, t_record *rec);

/*	hit_sphere.c	*/
bool	ft_hit_sph(t_sphere *sph, t_ray ray, double root_max, t_record *rec);
void	ft_set_rec_sph(double dist, t_sphere *sph, t_ray ray, t_record *rec);
bool	ft_solve_sph(t_sphere *sph, t_ray ray, double ret[2]);

/*	hit_cyl.c	*/
bool	ft_hit_cyl(t_cylinder cyl, t_ray ray, double dist_max, t_record *rec);
bool	ft_solve_cyl(t_cylinder cyl, t_ray ray, t_record temp[2]);
void	ft_copy_rec(t_record *rec, t_record *temp);

/*	hit_cyl_helper.c	*/
void	ft_inv_record(double inv[3][3], t_vec3 shift, t_record temp[2]);
void	ft_solve_cyl_top(t_cylinder cyl, t_ray ray, t_record *temp);
bool	ft_solve_cyl_body(t_cylinder cyl, t_ray ray, t_record rec[2]);
t_cylinder	ft_new_cyl(t_cylinder *cyl, double matrix[3][3]);
t_ray	ft_new_ray(t_ray *ray, double matrix[3][3], t_vec3 shift);

/*	ft_hit.c	*/
bool	ft_hit(t_object *world, t_ray ray, t_record *rec);
void	ft_init_rec(t_record *rec);



/*	ray_op.c	*/
t_vec3	ft_ray_at(t_ray ray, double t);

/*	ft_camera_ray.c	*/
t_ray	ft_camera_ray(t_canvas *canvas, int x, int y);
// t_rgb	create_rgb(char r, char g, char b);
void	pick_color(t_object *object, t_vec3 *color);

/*	ft_redef_space.c	*/
void	ft_redef_space(t_minirt	*minirt);

/* style */
void	alert(char *str, char *color);

/*	error */
void	error_manager(t_minirt *minirt, char *message, char *color);

#endif
