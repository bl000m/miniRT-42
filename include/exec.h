/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:09 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/21 13:31:28 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "mlx.h"
# include "parsing.h"

/*	init.c	*/
int		ft_init_mlx(t_minirt *minirt);

/*	hooks.c	*/
void	ft_set_hook(void *win);
int		ft_key_up_hook(int keycode, void *param);
int		ft_destroy_hook(void);


#endif