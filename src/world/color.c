/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:32:20 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/15 16:40:02 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "world.h"

t_rgb	create_rgb(int r, int g, int b)
{
	t_rgb	temp;

	temp.r = r;
	temp.g = g;
	temp.b = b;
	return (temp);
}
