/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cyl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:21:23 by hsliu             #+#    #+#             */
/*   Updated: 2023/03/27 11:05:23 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
	return only one record according to the value of dist_max
*/
bool	ft_hit_cyl(t_cylinder cyl, t_ray ray, double dist_max, t_record *rec)
{
	t_record	temp[2];

	if (!ft_solve_cyl(cyl, ray, temp))
	{
		return (FALSE);
	}
	else if (temp[0].dist < dist_max && temp[0].dist > 0.001)
	{
		ft_copy_rec(rec, temp);
		return (TRUE);
	}
	else if (temp[1].dist < dist_max && temp[1].dist > 0.001)
	{
		ft_copy_rec(rec, temp + 1);
		return (TRUE);
	}
	return (FALSE);
}


/*
	if no hit, return false
	ray : A + tB
	cylinder: 
	solve t and keep the result in temp[2]
	t is not effected by change base
	the record are inverted back at the end
	note:
	the function MUST take a copy of cyl cause it modifies the cyl
*/
bool	ft_solve_cyl(t_cylinder cyl, t_ray ray, t_record temp[2])
{
	double		matrix[3][3];
	double		inv[3][3];
	t_vec3		shift;
	
	ft_rotate_xyz(cyl.dir, matrix, inv)
	shift = cyl.center;
	ray = ft_new_ray(&ray, matrix, shift);
	cyl = ft_new_cyl(&cyl, matrix);
	if (!ft_solve_cyl_body(cyl, ray, temp))
	{
		return (FALSE);
	}
	ft_solve_cyl_top(cyl, ray, temp);
	ft_solve_cyl_top(cyl, ray, temp + 1);
	ft_inv_record(inv, shift, temp);
	if (temp[0].dist == -1 && temp[1].dist == -1)
	{
		return (FALSE);
	}
	return (TRUE);
}

void	ft_copy_rec(t_record *rec, t_record *temp)
{
	rec->dist = temp->dist;
	rec->pos = temp->pos;
	rec->normal = temp->normal;
	rec->color = temp->color;
}
