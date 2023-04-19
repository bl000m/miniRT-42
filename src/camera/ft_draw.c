/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:15:42 by sasha             #+#    #+#             */
/*   Updated: 2023/04/19 15:50:33 by sasha            ###   ########.fr       */
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
		while (j < minirt->canvas.img_width)
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

/*
void	ft_put_pixel(t_image *img, int x, int y, t_vec3 color)
{
	int		index;
	double	factor;
	int		temp;

	index = y * img->line_byte + x * img->pixel_bit / 8;
	if (img->endian == 1)
	{
		img->buffer[index + 0] = (color >> 24);
		img->buffer[index + 1] = (color >> 16) & 0xFF;
		img->buffer[index + 2] = (color >> 8) & 0xFF;
		img->buffer[index + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->buffer[index + 0] = (color) & 0xFF;
		img->buffer[index + 1] = (color >> 8) & 0xFF;
		img->buffer[index + 2] = (color >> 16) & 0xFF;
		img->buffer[index + 3] = (color >> 24);
	}
}
*/