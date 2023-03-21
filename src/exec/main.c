/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:16:24 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/21 14:45:02 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"
/*
    for testing
*/
int main(void)
{
    t_minirt	minirt;
    
    if (ft_init_mlx(&minirt))
    {
        write(2, "init fails\n", 11);
    }
    ft_set_hook(minirt.win)
    mlx_loop(minirt.mlx);
    
}
