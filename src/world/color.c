/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:32:20 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/16 06:58:01 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "world.h"

t_rgb	create_rgb(int r, int g, int b)
{
	t_rgb	*temp;

	temp = ft_calloc(sizeof(*temp), 1);
	if (!temp)
		printf("set error + return\n");
	temp->r = r;
	temp->g = g;
	temp->b = b;
	return (*temp);
}
