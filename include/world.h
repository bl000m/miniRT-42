/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:02:47 by sasha             #+#    #+#             */
/*   Updated: 2023/03/19 16:05:57 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <math.h>
# include <stdlib.h>

# ifndef SPH
#  define SPH 0
# endif

# ifndef PLN
#  define PLN 1
# endif

# ifndef CYL
#  define CYL 2
# endif

typedef struct s_vec3	t_vec3;

typedef struct	s_node
{
	int		type;
	void	*hittable;
	t_node	*next;
}	t_node;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

/*	list_op1.c	*/
t_node	*ft_new_sphere(t_vec3 cent, double r);
void	ft_add_node(t_node **head, t_node *node);
void	ft_del_lst(t_node **head);

/*	vector in 3d space	*/
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;	
}	t_vec3;

/*	vector_op1.c	*/
t_vec3	ft_add(t_vec3 v1, t_vec3 v2);
t_vec3	ft_sub(t_vec3 v1, t_vec3 v2);
t_vec3	ft_mul(t_vec3 v1, double t);
t_vec3	ft_div(t_vec3 v1, double t);
double	ft_dot(t_vec3 v1, t_vec3 v2);

/*	vector_op2.c	*/
double	ft_squr_len(t_vec3 v);
double	ft_veclen(t_vec3 v);
t_vec3	ft_unit_vec(t_vec3 v);
t_vec3	ft_rev_vec(t_vec3 v);

#endif