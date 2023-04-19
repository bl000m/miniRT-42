/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:56:01 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/19 17:34:12 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include "scene.h"


int	main(int argc, char **argv)
{
	t_minirt	minirt;
	t_object	*temp;
	int			error;

	(void)argc;
	error = 0;
	if (!ft_init(&minirt))
		return (1);
	if (read_rt_map(argv[1], &minirt, &error))
	{
		error_manager(&minirt, "Parsing error. Try again", RED);
		return (1);
	}
	ft_set_hook(&minirt);
	setting_canvas(&minirt);
	ft_redef_space(&minirt);
	temp = minirt.scene->objects;
	generating_camera_ray_draw(&minirt, temp);
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img, 0, 0);
	mlx_loop(minirt.mlx);

	return (0);
}
