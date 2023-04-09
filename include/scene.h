/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:11:05 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/09 15:30:39 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parsing.h"
# include "world.h"
# include <stdio.h>
# include <fcntl.h>

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
    char    *buf;
    int     pixel_bit;
    int     line_byte;
    int     endian;
}   t_image;

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
	t_map		*rt_map;
	t_scene		*scene;
	//ambient light
    //light source
}	t_minirt;

void	read_rt_map(char *source, t_minirt *minirt);
int		open_file_map(char *file_map);
void    initialize_plane(t_minirt *minirt, char **tokens);
void    initialize_sphere(t_minirt *minirt, char **tokens);
void    initialize_cylinder(t_minirt *minirt, char **tokens);
void    initialize_ambient_light(t_minirt *minirt, char **tokens);
void    initialize_camera(t_minirt *minirt, char **tokens);
void    initialize_light(t_minirt *minirt, char **tokens);
void	get_size(char *file_map, t_minirt *minirt);
int		get_n_lines(int fd);
t_vec3 	get_instruction(char **tokens, int index);
double 	get_instruction_double(char **tokens, int index);
int    	check_commas(char *token);
void    add_new_plane_object(t_minirt *minirt, t_plane *new_object_content);
void    add_new_sphere_object(t_minirt *minirt, t_sphere *new_object_content);
void    add_new_cylinder_object(t_minirt *minirt, t_cylinder *new_object_content);


#endif
