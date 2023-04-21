/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:09 by hsliu             #+#    #+#             */
/*   Updated: 2023/04/21 13:13:46 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "world.h"
# include "scene.h"
# include <stdio.h>
# include <stdbool.h>
# include <X11/keysym.h>

/*	init.c	*/
bool	ft_init_mlx(t_minirt *minirt);
bool	ft_init(t_minirt *minirt);
bool	ft_init_map(t_minirt *minirt);
bool	ft_init_scene(t_minirt *minirt);
bool	ft_init_objects(t_scene **scene);

/*	hooks.c	*/
void	ft_set_hook(t_minirt *minirt);
int		ft_key_up_hook(int keycode, void *param);
int		ft_destroy_hook(void *param);

#endif
