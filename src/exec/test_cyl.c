/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:10:16 by sasha             #+#    #+#             */
/*   Updated: 2023/03/27 15:20:19 by sasha            ###   ########.fr       */
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
	printf("set canvas\n");
	minirt.canvas.eps = 0.01;
	minirt.canvas.pos = ft_vec(-2, -1.13, -1);
	
	/*	define sphere	*/
	printf("def cyl\n");
	t_cylinder	cyl;
	cyl.center = ft_vec(0, 0, -30);
	cyl.dir = ft_vec(1, 2, 3);
	cyl.diameter = 1;
	cyl.height = 5;
	cyl.color =  ft_vec(100, 100, 100);
	
	/*	generate camera ray and draw	*/
	printf("draw\n");
	int			x;
	int			y;
	t_image		*img;
	t_ray		ray;
	t_record	rec;

	img = minirt.img;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ft_camera_ray(&(minirt.canvas), x, y);
			if (ft_hit_cyl(cyl, ray, 1000, &rec))
			{
				printf("o");
				ft_put_pixel(img, x, HEIGHT - y, 0xFFFFFF);
			}
			else
			{
				printf(" ");
				ft_put_pixel(img, x, HEIGHT - y, 0x0);
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

static void	ft_put_pixel(t_image *img, int x, int y, int color)
{
	int		index;

	index = (HEIGHT - y) * img->line_byte + x * img->pixel_bit / 8;
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
