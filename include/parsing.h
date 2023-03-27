/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:34:49 by sasha             #+#    #+#             */
/*   Updated: 2023/03/27 13:40:13 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "world.h"
//include light.h
# include "mlx.h"
# include "camera.h"

# ifndef WIDTH
#  define WIDTH 400
# endif

# ifndef HEIGHT
#  define HEIGHT 226
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
	t_vec3	pos;
	double	eps;
}	t_canvas;

typedef struct s_minirt
{
	void        *mlx;
    void        *win;
	t_image     *img;
	t_canvas	canvas;
	t_node		*world;
	//ambient light 
    //light source
}	t_minirt;

/*	
	move it if it's more suitable in light.h
*/
typedef struct s_light
{
	t_vec3	pos;
	t_vec3	color;
}	t_light;

#endif