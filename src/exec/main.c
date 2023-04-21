/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:56:01 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/20 20:50:08 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include "scene.h"

//remember to code strtod before push
int	main(int argc, char **argv)
{
	t_minirt	minirt;
	t_object	*temp;
	int			error;

	(void)argc;
	error = 0;
	if (argc != 2)
	{
		alert("Wrong number of argument", BLUE);
		exit(1);
	}
	if (!ft_init(&minirt))
		error_manager(&minirt, "Error: Init fails", RED);
	if (read_rt_map(argv[1], &minirt, &error))
		error_manager(&minirt, "Error: Parsing error. Try again", RED);
	ft_redef_space(&minirt);
	if (!ft_init_mlx(&minirt))
		error_manager(&minirt, "Error: Mlx init error", RED);
	ft_set_hook(&minirt);
	temp = minirt.scene->objects;
	generating_camera_ray_draw(&minirt, temp);
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img, 0, 0);
	mlx_loop(minirt.mlx);
	free_clean(&minirt);
	return (0);
}
