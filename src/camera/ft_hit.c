/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:42:24 by hsliu             #+#    #+#             */
/*   Updated: 2023/04/21 12:49:51 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "scene.h"
#include "world.h"

bool	ft_hit(t_object *world, t_ray ray, t_record *rec)
{
	t_object	*temp;
	int			hit;

	ft_init_rec(rec);
	temp = world;
	hit = 0;
	while (temp)
	{
		if (temp->type == 's')
			hit += ft_hit_sph(temp->sphere, ray, rec->dist, rec);
		else if (temp->type == 'c')
			hit += ft_hit_cyl(*temp->cylinder, ray, rec->dist, rec);
		else if (temp->type == 'p')
			hit += ft_hit_plane(temp->plane, ray, rec->dist, rec);
		temp = temp->next;
	}
	if (hit == 0)
		return (FALSE);
	return (TRUE);
}

void	ft_init_rec(t_record *rec)
{
	rec->pos.x = 0;
	rec->pos.y = 0;
	rec->pos.z = 0;
	rec->normal.x = 0;
	rec->normal.y = 0;
	rec->normal.z = 0;
	rec->color.x = 0;
	rec->color.y = 0;
	rec->color.z = 0;
	rec->dist = INFINITY;
}
