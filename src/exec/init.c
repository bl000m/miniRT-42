/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:42 by hsliu             #+#    #+#             */
/*   Updated: 2023/04/09 18:40:41 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "scene.h"
#include "world.h"

/*
    return 1 if there's error
    this function should init and parse everything
    but right now it's just for testing
*/
bool	ft_init_mlx(t_minirt *minirt)
{
	t_image	*img_info;

	img_info = &(minirt->img_info);
	minirt->mlx = mlx_init();
	if (minirt->mlx == NULL)
	{
		return (FALSE);
	}
	minirt->win = mlx_new_window(minirt->mlx, WIDTH, HEIGHT, "MiniRT");
	if (minirt->win == NULL)
	{
		mlx_destroy_display(minirt->mlx);
		free(minirt->mlx);
		return (FALSE);
	}
	minirt->img = mlx_new_image(minirt->mlx, WIDTH, HEIGHT);
	if (minirt->img == NULL)
	{
		mlx_destroy_window(minirt->mlx, minirt->win);
		mlx_destroy_display(minirt->mlx);
		free(minirt->mlx);
		return (FALSE);
	}
	img_info->buf = mlx_get_data_addr(minirt->img, &(img_info->pixel_bit),
				&(img_info->line_byte), &(img_info->endian));
	return (TRUE);
}

bool	ft_init_objects(t_scene **scene)
{
	t_object	*objects;

	objects = malloc(sizeof(*objects));
	if (!objects)
		return (FALSE);
	objects->plane = malloc(sizeof(t_plane));
	if (!objects->plane)
		return (FALSE);
	objects->plane = NULL;
	objects->sphere = NULL;
	objects->cylinder = NULL;
	objects->type = 0;
	objects->first = 0;
	objects->next = NULL;
	(*scene)->objects = objects;
	return (TRUE);
}

bool	ft_init_map(t_minirt *minirt)
{
	t_map	*rt_map;

	rt_map = malloc(sizeof(*rt_map));
	if (!rt_map)
		return (FALSE);
	rt_map->n_lines = 0;
	minirt->rt_map = rt_map;
	return (TRUE);
}

bool	ft_init_scene(t_minirt *minirt)
{
	t_scene	*scene;
	int		ret;

	ret = TRUE;
	scene = malloc(sizeof(*scene));
	if (!scene)
		return (FALSE);
	scene->ambient_light = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	ret = ft_init_objects(&scene);
	minirt->scene = scene;
	return (ret);
}

bool	ft_init(t_minirt *minirt)
{
	int	ret;

	ret = ft_init_mlx(minirt);
	ret += ft_init_map(minirt);
	ret += ft_init_scene(minirt);
	printf("ret in ft_init = %d\n", ret);
	return (ret);
}
