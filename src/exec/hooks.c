/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:05:54 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/27 12:18:14 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_set_hook(t_minirt *minirt)
{
	mlx_hook(minirt->win, 3, 0, ft_key_up_hook, minirt);
	mlx_hook(minirt->win, 17, 0, ft_destroy_hook, minirt);
}


/*
    do we need to free minirt->mlx ???
*/
int	ft_key_up_hook(int keycode, void *param)
{
	t_minirt    *minirt;

	if (keycode != 53)
		return (0);
    minirt = (t_minirt *)param;
	mlx_destroy_image(minirt->mlx, minirt->img);
	mlx_destroy_window(minirt->mlx, minirt->win);
	mlx_destroy_display(minirt->mlx);
	exit(0);
}

int	ft_destroy_hook(void *param)
{
	t_minirt    *minirt;

    minirt = (t_minirt *)param;
	mlx_destroy_display(minirt->mlx);
    exit(0);
}