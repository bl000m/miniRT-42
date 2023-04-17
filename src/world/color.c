/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:32:20 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/17 06:55:54 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "world.h"

// t_rgb	create_rgb(char r, char g, char b)
// {
// 	t_rgb	*temp;

// 	temp = ft_calloc(sizeof(*temp), 1);
// 	if (!temp)
// 		printf("set error + return\n");
// 	temp->r = (uint8_t)r;
// 	temp->g = (uint8_t)g;
// 	temp->b = (uint8_t)b;
// 	return (*temp);
// }

void	pick_color(t_object *object, t_vec3 *color)
{
	if (object->type == 's')
		*color = object->sphere->color;
	else if (object->type == 'c')
		*color = object->cylinder->color;
	else if (object->type == 'p')
		*color = object->plane->color;
}