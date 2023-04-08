/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:34:49 by sasha             #+#    #+#             */
/*   Updated: 2023/04/08 14:11:37 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "world.h"
//include light.h
# include "mlx.h"
# include "scene.h"
# include "camera.h"
# include "../libft/libft.h"

# ifndef WIDTH
#  define WIDTH 2400
# endif

# ifndef HEIGHT
#  define HEIGHT 1360
# endif

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


#endif
