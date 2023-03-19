/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:34:49 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 21:54:50 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "world.h"
//include light.h
//include mlx.h

# ifndef WIDTH
#  define WIDTH 400
# endif

# ifndef HEIGHT
#  define HEIGHT 225
# endif

typedef struct s_minirt
{
	//window ptr
	//img ptr
	t_canvas	canvas;
	t_node		*world;
	//light
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