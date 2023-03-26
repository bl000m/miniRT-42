/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:08:42 by sasha             #+#    #+#             */
/*   Updated: 2023/03/26 18:05:18 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

/*
	take the new z, calculate the linear transformation matrix
	it will first normalized z
	inv will keep the inverse of the matrix
*/
int	ft_rotate_xyz(t_vec3 z, double matrix[3][3], double inv[3][3])
{
	t_vec3	x;
	t_vec3	y;

	z = ft_unit_vec(z);
	x = ft_unit(ft_cross(ft_vec(0, 1, 0), z));
	if (ft_is_zero(x))
	{
		x = ft_vec(1, 0, 0);
	}
	y = ft_unit(ft_cross(z, x));
	ft_vec_to_matrix(x, y, z, inv);
	if (ft_matrix_inv(inv, matrix))
	{
		return (1);
	}
	return (0);
}

/*
	write three vectors into matrix m, so that m = [a1 a2 a3] 
*/
void	ft_vec_to_matrix(t_vec3 a1, t_vec3 a2, t_vec3 a3, double m[3][3])
{
	m[0][0] = a1.x;
	m[1][0] = a1.y;
	m[2][0] = a1.z;
	m[0][1] = a2.x;
	m[1][1] = a2.y;
	m[2][1] = a2.z;
	m[0][2] = a3.x;
	m[1][2] = a3.y;
	m[2][2] = a3.z;
}

/*
	matrix inverse
	the input is A = [a1 a2 a3]
	the output is put in matrix[3][3]
	return 1, if matrix is not invertible
*/
int	ft_matrix_inv(double m[3][3], double inv[3][3])
{
	double	det;
	double	invdet;

	det = m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
		- m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
    	+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	if (det == 0)
	{
		write(2, "matrix not invertible\n", 22);
		return (1);
	}
	invdet = 1 / det;
	inv[0][0] = (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * invdet;
	inv[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * invdet;
	inv[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invdet;
	inv[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * invdet;
	inv[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invdet;
	inv[1][2] = (m[1][0] * m[0][2] - m[0][0] * m[1][2]) * invdet;
	inv[2][0] = (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * invdet;
	inv[2][1] = (m[2][0] * m[0][1] - m[0][0] * m[2][1]) * invdet;
	inv[2][2] = (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * invdet;
	return (0);
}

/*
	Calculate Ax = b
*/
t_vec3	ft_matrix_mul(double matrix[3][3], t_vec3 x)
{
	t_vec3	temp;

	temp.x = matrix[0][0] * x.x + matrix[0][1] * x.y + matrix[0][2] * x.z;
	temp.y = matrix[1][0] * x.x + matrix[1][1] * x.y + matrix[1][2] * x.z;
	temp.z = matrix[2][0] * x.x + matrix[2][1] * x.y + matrix[2][2] * x.z;
	return (temp);
}
