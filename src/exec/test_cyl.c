/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:10:16 by sasha             #+#    #+#             */
/*   Updated: 2023/03/31 12:44:01 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include <stdio.h>

static void	ft_put_pixel(t_image *img, int x, int y, int color);


static int	ft_vec_to_int(t_vec3 color)
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


/*
static void	ft_print_matrix(double m[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%f ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
*/

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
	
	/*	set canvas	*/
	printf("set canvas\n");
	minirt.canvas.eps = 0.01;
	minirt.canvas.pos = ft_vec((WIDTH / 2) * -0.01, (HEIGHT / 2) * -0.01, -30);
		
	/*	define sphere	*/
	printf("def cyl\n");
	t_cylinder	cyl;
	cyl.center = ft_vec(2, 0, -30);
	cyl.dir = ft_unit_vec(ft_vec(-1, 2, -3));
	cyl.diameter = 1;
	cyl.height = 10;
	cyl.color =  ft_vec(100, 100, 100);
	
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
			if (ft_hit_cyl(cyl, ray, 1000000, &rec))
			{
				//printf("o");
				ft_put_pixel(img_info, x, y, ft_vec_to_int(rec.normal));
			}
			else
			{
				//printf(" ");
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
