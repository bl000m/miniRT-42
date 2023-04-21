/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:53:20 by mathia            #+#    #+#             */
/*   Updated: 2023/04/21 13:02:20 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	ft_vec_to_int(t_vec3 color)
{
	int	temp;

	temp = 0;
	temp |= (int)(color.x) << 0;
	temp |= (int)(color.y) << 8;
	temp |= (int)(color.z) << 16;
	return (temp);
}

bool	stocking_rec_depending_on_objects(t_minirt *minirt, t_object *object)
{
	if (object->type == 's')
		return (ft_hit_sph(object->sphere, minirt->ray, \
			minirt->rec.dist, &(minirt->rec)));
	else if (object->type == 'c')
		return (ft_hit_cyl(*object->cylinder, minirt->ray, \
			minirt->rec.dist, &(minirt->rec)));
	return (FALSE);
}

void	initialize_rec(t_minirt *minirt)
{
	minirt->rec.pos.x = 0;
	minirt->rec.pos.y = 0;
	minirt->rec.pos.z = 0;
	minirt->rec.normal.x = 0;
	minirt->rec.normal.y = 0;
	minirt->rec.normal.z = 0;
	minirt->rec.color.x = 0;
	minirt->rec.color.y = 0;
	minirt->rec.color.z = 0;
	minirt->rec.dist = INFINITY;
}

void	generating_camera_ray_draw(t_minirt *minirt, t_object *object)
{
	bool		hit;
	t_vec3		color;

	minirt->y = 0;
	while (minirt->y < HEIGHT)
	{
		minirt->x = 0;
		while (minirt->x < minirt->canvas.img_width)
		{
			color = ft_vec(0.0, 0.0, 0.0);
			minirt->ray = ft_camera_ray(&(minirt->canvas), \
				minirt->x, minirt->y);
			hit = ft_hit(object, minirt->ray, &(minirt->rec));
			if (hit)
			{
				color = ft_mix_light(minirt, &(minirt->rec));
			}
			ft_put_pixel(&(minirt->img_info), minirt->x, minirt->y, \
				ft_vec_to_int(color));
			minirt->x++;
		}
		minirt->y++;
	}
}

void	ft_put_pixel(t_image *img_info, int x, int y, int color)
{
	int		index;

	index = y * img_info->line_byte + x * img_info->pixel_bit / 8;
	if (img_info->endian == 1)
	{
		img_info->buf[index + 0] = (color >> 24);
		img_info->buf[index + 1] = (color >> 16) & 0xFF;
		img_info->buf[index + 2] = (color >> 8) & 0xFF;
		img_info->buf[index + 3] = (color) & 0xFF;
	}
	else if (img_info->endian == 0)
	{
		img_info->buf[index + 0] = (color) & 0xFF;
		img_info->buf[index + 1] = (color >> 8) & 0xFF;
		img_info->buf[index + 2] = (color >> 16) & 0xFF;
		img_info->buf[index + 3] = (color >> 24);
	}
}
