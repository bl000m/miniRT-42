/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:32:20 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/20 20:52:29 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "world.h"

void	pick_color(t_object *object, t_vec3 *color)
{
	if (object->type == 's')
		*color = object->sphere->color;
	else if (object->type == 'c')
		*color = object->cylinder->color;
	else if (object->type == 'p')
		*color = object->plane->color;
}