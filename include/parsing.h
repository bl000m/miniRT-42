/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:34:49 by sasha             #+#    #+#             */
/*   Updated: 2023/03/21 13:00:00 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "world.h"
//include light.h
# include "mlx.h"

# ifndef WIDTH
#  define WIDTH 400
# endif

# ifndef HEIGHT
#  define HEIGHT 225
# endif

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

typedef struct s_image
{
    char    *buf;
    int     pixel_bit;
    int     line_byte;
    int     endian;
}   t_image;



/*	
	move it if it's more suitable in light.h
*/
typedef struct s_light
{
	t_vec3	pos;
	t_vec3	color;
}	t_light;

#endif