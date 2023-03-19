/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:15:42 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 21:54:54 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
	minirt is a struct contains :
	t_img *canvas, t_node *world, light_src
*/
void	ft_draw_canvas(t_minirt *minirt)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			//ft_draw_pixel
			j++;
		}
		i++;
	}
}

void	ft_draw_pixel(int x, int y, t_minirt *minirt)
{
	t_record	record;
	t_ray		ray;
	t_vec3		color;

	ray = ft_camera_ray(minirt.canvas, x, y);
	/*	pseudo code : 
	if (ft_hit(ray, world, &record))
	{
		color = ft_color(ray, record, minirt)
	}
	else
	{
		color = black
	}
	draw color to pixel(x, y)
	*/
}