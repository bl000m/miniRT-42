/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:53:20 by mathia            #+#    #+#             */
/*   Updated: 2023/04/09 18:45:08 by mathia           ###   ########.fr       */
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

// void    putting_pixel_depending_on_objects(char type)
// {
//     if (type == 'p')
//         return ;
//     else if (type == 's')
//     {
//         if (ft_hit_sph(&sph, ray, 10000, &rec))
//             ft_put_pixel(img_info, x, y, ft_vec_to_int(rec.normal));
//         else
//             ft_put_pixel(img_info, x, y, 0x0);
//     }
//     else if (type == 'c')
//         return ;
// }

void    generating_camera_ray_draw(t_minirt *minirt, t_object *object)
{
    int			x;
	int			y;
	t_image		*img_info;
	t_ray		ray;
	t_record	rec;

	img_info = &(minirt->img_info);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ft_camera_ray(&(minirt->canvas), x, y);
            if (object->type == 's')
            {
                if (ft_hit_sph(object->sphere, ray, 10000, &rec))
                    ft_put_pixel(img_info, x, y, ft_vec_to_int(rec.normal));
                else
                    ft_put_pixel(img_info, x, y, 0x0);
            }
            else
                return ;
			x++;
		}
		y++;
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