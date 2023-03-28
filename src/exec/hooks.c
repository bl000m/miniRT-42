/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:05:54 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/28 13:50:19 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "stdio.h"
#include <X11/keysym.h>

void	ft_set_hook(t_minirt *minirt)
{
	mlx_hook(minirt->win, 3, 0, ft_key_up_hook, minirt);
	mlx_hook(minirt->win, 17, 1L<<1, ft_destroy_hook, minirt);
	//mlx_key_hook(minirt->win, &ft_key_hook, minirt);
}


/*
    do we need to free minirt->mlx ???
*/
int	ft_key_up_hook(int keycode, void *param)
{
	t_minirt    *minirt;

	printf("hooks\n");
	if (keycode != 65307)
		return (0);
    minirt = (t_minirt *)param;
	mlx_destroy_image(minirt->mlx, minirt->img);
	mlx_destroy_window(minirt->mlx, minirt->win);
	mlx_destroy_display(minirt->mlx);
	free(minirt->mlx);
	exit(0);
}

/*	exit when the window is closed	*/
int	ft_destroy_hook(void *param)
{
	t_minirt    *minirt;

    minirt = (t_minirt *)param;
	mlx_destroy_image(minirt->mlx, minirt->img);
	mlx_destroy_window(minirt->mlx, minirt->win);
	mlx_destroy_display(minirt->mlx);
	free(minirt->mlx);
    exit(0);
}
