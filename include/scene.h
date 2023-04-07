/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:11:05 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/07 18:10:42 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parsing.h"

typedef struct s_ambient
{
	double	ratio;
	t_vec3	color;
}	t_ambient;

typedef struct s_light
{
	t_vec3	pos;
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
	void		*content;
	t_object	next;
}	t_object;

typedef struct s_scene
{
	t_ambient	*ambient_light;
	t_camera	*camera;
	t_light		*light;
	t_object	*sphere;
	t_object	*cylinder;
	t_object	*plane;
}	t_scene;

int	open_file_map(char *file_map);


#endif
