/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:56:01 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/08 13:59:04 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	if (!ft_init(&minirt))
	{
		(void) (write(2, "init fails\n", 11) + 1);
		return (1);
	}
	read_rt_map(argv[1], &minirt);
	ft_set_hook(&minirt);
	//set canvas
	//initialize objects
	//generate camera ray and draw
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img, 0, 0);
	mlx_loop(minirt.mlx);
	return (0);
}
