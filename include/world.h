/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:02:47 by sasha             #+#    #+#             */
/*   Updated: 2023/03/27 12:25:39 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef SPH
#  define SPH 0
# endif

# ifndef PLN
#  define PLN 1
# endif

# ifndef CYL
#  define CYL 2
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

/*	vector in 3d space	*/
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;	
}	t_vec3;

typedef struct	s_node	t_node;

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
	t_vec3	color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec3	center;
    t_vec3  dir;
	double	diameter;
    double	height;
	t_vec3	color;
}	t_cylinder;

/*	list_op1.c	*/
t_node	*ft_new_sphere(t_vec3 cent, double r);
void	ft_add_node(t_node **head, t_node *node);
void	ft_del_lst(t_node **head);

/*	vector_op1.c	*/
t_vec3	ft_add(t_vec3 v1, t_vec3 v2);
t_vec3	ft_sub(t_vec3 v1, t_vec3 v2);
t_vec3	ft_mul(t_vec3 v1, double t);
t_vec3	ft_div(t_vec3 v1, double t);
t_vec3	ft_rev_vec(t_vec3 v);

/*	vector_op2.c	*/
double	ft_squr_len(t_vec3 v);
double	ft_veclen(t_vec3 v);
t_vec3	ft_unit_vec(t_vec3 v);
double	ft_dot(t_vec3 v1, t_vec3 v2);
t_vec3	ft_cross(t_vec3 u, t_vec3 v);

/*	vector_op3.c	*/
t_vec3	ft_vec(double x, double y, double z);
bool	ft_is_zero(t_vec3 v);


/*	matrix_op.c	*/
void	ft_rotate_xyz(t_vec3 z, double matrix[3][3], double inv[3][3]);
void	ft_vec_to_matrix(t_vec3 a1, t_vec3 a2, t_vec3 a3, double m[3][3]);
void	ft_matrix_inv(double m[3][3], double inv[3][3]);
t_vec3	ft_matrix_mul(double matrix[3][3], t_vec3 x);

/*	math_utils.c	*/
double	ft_dabs(double x);

#endif