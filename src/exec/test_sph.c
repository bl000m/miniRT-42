/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:16:24 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/29 12:29:39 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include <stdio.h>

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include <stdio.h>

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include <stdio.h>

static void	ft_put_pixel(t_image *img, int x, int y, int color);

// static void	ft_print_vec(t_vec3 v)
// {
// 	printf("(%.3g, %.3g)", v.x, v.y);
// }

/*
    for testing
*/
int main(void)
{
	t_minirt	minirt;

	if (!ft_init_mlx(&minirt))
	{
		(void) (write(2, "init fails\n", 11) + 1);
		return (0);
    }
	
	ft_set_hook(&minirt);
	
	/*	set canvas and camera	*/
	printf("set canvas and camera\n");
	minirt.canvas.eps = 0.01;
	minirt.canvas.pos = ft_vec((WIDTH / 2) * -0.01, (HEIGHT / 2) * -0.01, -20);
	
	
	/*	define sphere	*/
	printf("def sph\n");
	t_sphere	sph;
	sph.center = ft_vec(-2, -2, -50);
	sph.radius = 2;
	sph.color =  ft_vec(100, 100, 100);
	
	/*	generate camera ray and draw	*/
	printf("draw\n");
	int			x;
	int			y;
	t_image		*img_info;
	t_ray		ray;
	t_record	rec;

	img_info = &(minirt.img_info);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ft_camera_ray(&(minirt.canvas), x, y);
			if (ft_hit_sph(&sph, ray, 10000, &rec))
			{
				//printf("o");
				ft_put_pixel(img_info, x, y, 0xFFFFFF);
			}
			else
			{
				//printf("x");
				ft_put_pixel(img_info, x, y, 0x0);
			}
			x++;
		}
		y++;
	}
	
	//put image to win
	printf("image\n");
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img, 0, 0);
	mlx_loop(minirt.mlx);
}

static void	ft_put_pixel(t_image *img_info, int x, int y, int color)
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
