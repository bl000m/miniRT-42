/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:56:01 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/24 16:11:10 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "mlx.h"
#include "exec.h"
#include "scene.h"

int	main(int argc, char **argv)
{
	t_minirt	minirt;
	t_object	*temp;
	int			error;

	error = 0;
	check_arguments(argc);
	if (!ft_init(&minirt))
		error_manager(&minirt, "Error: Init fails", RED);
	if (read_rt_map(argv[1], &minirt, &error))
		error_manager(&minirt, "Error: Parsing error. Try again", RED);
	ft_redef_space(&minirt);
	if (!ft_init_mlx(&minirt))
		error_manager(&minirt, "Error: Mlx init error", RED);
	ft_set_hook(&minirt);
	temp = minirt.scene->objects;
	if (minirt.scene->camera.fov > 0)
		generating_camera_ray_draw(&minirt, temp);
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img, 0, 0);
	mlx_loop(minirt.mlx);
	free_clean(&minirt);
	return (0);
}
