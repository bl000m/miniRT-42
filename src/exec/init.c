/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:42 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/21 13:05:02 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
    return 1 if there's error
    this function should init and parse everything
    but right now it's just for testing
*/
int ft_init_mlx(t_minirt *minirt)
{
	t_image	*img;
	
	minirt->mlx = mlx_init();
	if (minirt->mlx == NULL)
	{
		return (1);
	}
	minirt->win = mlx_new_window(minirt->mlx, WIDTH, HEIGHT, "MiniRT");
	if (minirt->win == NULL)
	{
		mlx_destroy_display(minirt->mlx);
		return (1);
	}
	minirt->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	if (minirt->img == NULL)
	{
		mlx_destroy_window(minirt->mlx, minirt->win);
		mlx_destroy_display(minirt->mlx);
		return (1);
	}
	img = minirt->img;
	img->buf = mlx_get_data_addr(img, &(img->pixel_bit),
				&(img->line_byte), &(img->endian));
	return (0);
}