/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:06:52 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/20 10:36:55 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include "scene.h"

void	free_scene(t_minirt *minirt)
{
	t_object *temp;
	t_object *ptr;

	temp = minirt->scene->objects;
	while (temp)
	{
		if (temp->cylinder)
			free(temp->cylinder);
		if (temp->sphere)
			free(temp->sphere);
		if (temp->plane)
			free(temp->plane);
		ptr = temp;
		temp = temp->next;
		free(ptr);
	}
	free(minirt->scene);
}

void	free_mlx(t_minirt *minirt)
{
	mlx_destroy_image(minirt->mlx, minirt->img);
	mlx_destroy_window(minirt->mlx, minirt->win);
	mlx_destroy_display(minirt->mlx);
	free(minirt->mlx);
}

void	free_clean(t_minirt *minirt)
{
	// if (minirt->mlx)
	// 	free_mlx(minirt);
	if (minirt->scene)
		free_scene(minirt);
}

void	error_manager(t_minirt *minirt, char *message, char *color)
{
	// (void) minirt;
	if (message)
	{
		free_clean(minirt);
		alert(message, color);
	}
	exit (1);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
}
