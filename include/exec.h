/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:09 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/27 12:24:57 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "mlx.h"
# include "parsing.h"
# include "world.h"
# include <stdbool.h>

/*	init.c	*/
bool	ft_init_mlx(t_minirt *minirt);

/*	hooks.c	*/
void	ft_set_hook(t_minirt *minirt);
int		ft_key_up_hook(int keycode, void *param);
int		ft_destroy_hook(void *param);

#endif