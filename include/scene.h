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

# include "world.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# define GREEN "\x1b[32m"
# define BLUE "\x1b[94m"
# define RED "\x1b[91m"
# define INFO "\x1b[35m"
# define NORMAL "\x1b[m"

# ifndef HEIGHT
#  define HEIGHT 680
# endif

# ifndef WIDTH
#  define WIDTH 1020
# endif

# define ALBEDO 0.3

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
	double		fov;
}	t_camera;

typedef struct s_object
{
	t_plane			*plane;
	t_sphere		*sphere;
	t_cyl			*cylinder;
	char			type;
	int				first;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	t_ambient	ambient_light;
	t_camera	camera;
	t_light		light;
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
	t_vec3	pos;
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
	int			fd;
}	t_minirt;

/* parsing */
int		read_rt_map(char *source, t_minirt *minirt, int *error);
void	open_file_map(char *file_map, t_minirt *minirt);
int		initialize_plane(t_minirt *minirt, char **tokens, char *line);
int		initialize_sphere(t_minirt *minirt, char **tokens, char *line);
int		initialize_cylinder(t_minirt *minirt, char **tokens, char *line);
int		initialize_ambient_light(t_minirt *minirt, char **tokens, char *line);
int		initialize_camera(t_minirt *minirt, char **tokens, char *line);
int		initialize_light(t_minirt *minirt, char **tokens, char *line);
void	get_size(char *file_map, t_minirt *minirt);
int		get_n_lines(t_minirt *minirt, int *whitespaces);
t_vec3	get_instruction(char **tokens, int index, t_minirt *minirt, char *line);
double	get_ins_double(char **tokens, int index, t_minirt *minirt, char *line);
void	checking_id(t_minirt *minirt, char **tokens, \
		int *error, char *line);
int		check_commas(char *token);
void	add_new_plane_object(t_minirt *minirt, t_plane *new_object_content);
void	add_new_sphere_object(t_minirt *minirt, t_sphere *new_object_content);
void	add_new_cylinder(t_minirt *minirt, \
		t_cyl *new_object_content);
void	ft_put_pixel(t_image *img_info, int x, int y, int color);
void	generating_camera_ray_draw(t_minirt *minirt, t_object *object);
int		check_parameters(t_vec3 vector);
int		check_params_err(char **tokens);
int		tokens_number(char **tokens);
void	closing_fd(t_minirt *minirt);
int		check_double(char *token);
void	check_tokens(char **tokens, t_minirt *minirt, char *line);
int		check_numeric(char *token);
int		check_object_id(char *token);
void	check_quality_token(t_minirt *minirt, char **tokens);
void	elem_id_scenario(t_minirt *minirt, char **tokens, char *line);
void	object_id_scenario(t_minirt *minirt, char **tokens, char *line);
void	commas_scenario(t_minirt *minirt, char **tokens, char *line, int i);
void	finish_gnl(int fd);

/*	hit_plane.c	*/
bool	ft_hit_plane(t_plane *plane, t_ray ray, double dist_max, t_record *rec);

/*	hit_sphere.c	*/
bool	ft_hit_sph(t_sphere *sph, t_ray ray, double root_max, t_record *rec);
void	ft_set_rec_sph(double dist, t_sphere *sph, t_ray ray, t_record *rec);
bool	ft_solve_sph(t_sphere *sph, t_ray ray, double ret[2]);

/*	hit_cyl.c	*/
bool	ft_hit_cyl(t_cyl cyl, t_ray ray, double dist_max, t_record *rec);
bool	ft_solve_cyl(t_cyl cyl, t_ray ray, t_record temp[2]);
void	ft_copy_rec(t_record *rec, t_record *temp);

/*	hit_cyl_helper.c	*/
void	ft_inv_record(double inv[3][3], t_vec3 shift, t_record temp[2]);
void	ft_solve_cyl_top(t_cyl cyl, t_ray ray, t_record *temp);
bool	ft_solve_cyl_body(t_cyl cyl, t_ray ray, t_record rec[2]);
t_cyl	ft_new_cyl(t_cyl *cyl, double matrix[3][3]);
t_ray	ft_new_ray(t_ray *ray, double matrix[3][3], t_vec3 shift);

/*	ft_hit.c	*/
bool	ft_hit(t_object *world, t_ray ray, t_record *rec);
void	ft_init_rec(t_record *rec);

/*	ft_ambient_light.c	*/
t_vec3	ft_ambient_light(t_minirt *minirt, t_record *rec);
t_vec3	ft_diffuse_light(t_minirt *minirt, t_record *rec);
t_vec3	ft_spec_light(t_minirt *minirt, t_record *rec);
bool	ft_in_shadow(t_minirt *minirt, t_record *rec);
t_vec3	ft_mix_light(t_minirt *minirt, t_record *rec);
t_vec3	ft_fix_overflow(t_vec3 color);

/*	ray_op.c	*/
t_vec3	ft_ray_at(t_ray ray, double t);
t_ray	ft_init_ray(t_vec3 orig, t_vec3 dir);

/*	ft_camera_ray.c	*/
t_ray	ft_camera_ray(t_canvas *canvas, int x, int y);
void	pick_color(t_object *object, t_vec3 *color);

/*	ft_redef_space.c	*/
void	ft_redef_space(t_minirt	*minirt);

/* style */
void	alert(char *str, char *color);

/*	memory stuff */
void	free_clean(t_minirt *minirt);
void	error_manager(t_minirt *minirt, char *message, char *color);
void	ft_free(char **strs);
void	free_parsing(char **tokens, char *line);
void	check_scene_elem(char *line, int *al_p, int *c_p, int *l_p);
void	manage_scene_err(t_minirt *minirt, int al_p, int c_p, int l_p);
void	message_exit(char *message, t_minirt *minirt, \
	char **tokens, char *line);
void	check_arguments(int argc);

#endif
