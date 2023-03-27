/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:16:24 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/27 14:10:18 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include <stdio.h>

static void	ft_put_pixel(t_image *img, int x, int y, int color);

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
	ft_set_hook(minirt.win);
	/*	set canvas	*/
	minirt.canvas.eps = 0.01;
	minirt.canvas.pos = ft_vec(-2, -1.13, -1);
	
	/*	define sphere	*/
	t_sphere	sph;
	sph.center = ft_vec(0, 0, -3);
	sph.radius = 1;
	sph.color =  ft_vec(100, 100, 100);
	
	/*	generate camera ray and draw	*/
	int			x;
	int			y;
	t_image		*img;
	t_ray		ray;
	t_record	rec;

	img = minirt.img;
	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			ray = ft_camera_ray(&(minirt.canvas), x, y);
			if (ft_hit_sph(&sph, ray, 100, &rec))
			{
				printf("HELLO\n");
				ft_put_pixel(img, HEIGHT - x, y, 0xFFFFFF);
			}
			else
			{
				printf("coucou\n");
				ft_put_pixel(img, HEIGHT - x, y, 0x0);
			}
			y++;
		}
		x++;
	}
	
	//put image to win
	printf("image\n");
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img, 0, 0);
	mlx_loop(minirt.mlx);
}

static void	ft_put_pixel(t_image *img, int x, int y, int color)
{
	int		index;

	index = x * img->line_byte + y * img->pixel_bit / 8;
	if (img->endian == 1)
	{
		img->buf[index + 0] = (color >> 24);
		img->buf[index + 1] = (color >> 16) & 0xFF;
		img->buf[index + 2] = (color >> 8) & 0xFF;
		img->buf[index + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->buf[index + 0] = (color) & 0xFF;
		img->buf[index + 1] = (color >> 8) & 0xFF;
		img->buf[index + 2] = (color >> 16) & 0xFF;
		img->buf[index + 3] = (color >> 24);
	}
}
