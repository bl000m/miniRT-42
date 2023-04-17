/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:53:20 by mathia            #+#    #+#             */
/*   Updated: 2023/04/17 12:00:55 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include "scene.h"

int	ft_vec_to_int(t_vec3 color)
{
	int	temp;

	color = ft_unit_vec(color);
	color.x += 1;
	color.y += 1;
	color.z += 1;
	color = ft_unit_vec(color);
   // double	t = 0.5 * (color.y + 1.0);
   // color = ft_add(ft_mul(ft_vec(1.0, 1.0, 1.0), (1.0 - t)), ft_mul(ft_vec(0.5, 0.7, 1.0), t));

	temp = 0;
	temp |= (int)(color.x * 250) << 0; // blue
	temp |= (int)(color.y * 250) << 8; // green
	temp |= (int)(color.z * 250) << 16; //red
	return (temp);
}

void    setting_canvas(t_minirt *minirt)
{
	minirt->canvas.eps = 0.01;
	minirt->canvas.pos = ft_vec((WIDTH / 2) * -0.01, (HEIGHT / 2) * -0.01, -20);
}

	// printf("dist = %f\n", minirt->rec.dist);
bool    stocking_rec_depending_on_objects(t_minirt *minirt, t_object *object)
{
	if (object->type == 's')
		return (ft_hit_sph(object->sphere, minirt->ray, minirt->rec.dist, &(minirt->rec)));
	else if (object->type == 'c')
		return (ft_hit_cyl(*object->cylinder, minirt->ray, minirt->rec.dist, &(minirt->rec)));
	else if (object->type == 'p')
		return (ft_hit_plane(minirt, object->plane));
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

void    generating_camera_ray_draw(t_minirt *minirt, t_object *object)
{
	t_object	*temp;
	bool		hit;
	// t_vec3		color;

	minirt->y = 0;
	temp = object;
	while (minirt->y < HEIGHT)
	{
		minirt->x = 0;
		while (minirt->x < WIDTH)
		{
			// color = ft_vec(0.0, 0.0, 0.0);
			minirt->ray = ft_camera_ray(&(minirt->canvas), minirt->x, minirt->y);
			initialize_rec(minirt);
			hit = 0;
			while (temp)
			{
				hit += stocking_rec_depending_on_objects(minirt, temp);
				temp = temp->next;
			}
			temp = object;
			if (hit != 0)
			{
				// pick_color(temp, color);
				ft_put_pixel(&(minirt->img_info), minirt->x, minirt->y, ft_vec_to_int(minirt->rec.normal));
			}
			else
				ft_put_pixel(&(minirt->img_info), minirt->x, minirt->y, 0x0);
			minirt->x++;
		}
		minirt->y++;
		// free(color);
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
