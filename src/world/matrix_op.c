/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:08:42 by sasha             #+#    #+#             */
/*   Updated: 2023/03/20 17:09:20 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

/*
	matrix inverse
	the input is A = [a1 a2 a3]
	the output is put in matrix[3][3]
	return 1, if matrix is not invertible
*/
int	ft_matrix_inv(t_vec3 a1, t_vec3 a2, t_vec3 a3, double matrix[3][3])
{
	double	det;
	double	invdet;

	det = a1.x * (a2.y * a3.z - a3.y * a2.z)
		- a1.y * (a2.x * a3.z - a2.z * a3.x)
		+ a1.z * (a2.x * a3.y - a2.y * a3.x);
	if (det == 0)
	{
		write(2, "matrix not invertible\n", 22);
		return (1);
	}
	invdet = 1 / det;
	matrix[0][0] = (a2.y * a3.z - a3.y * a2.z) * invdet;
	matrix[0][1] = (a1.z * a3.y - a1.y * a3.z) * invdet;
	matrix[0][2] = (a1.y * a2.z - a1.z * a2.y) * invdet;
	matrix[1][0] = (a2.z * a3.x - a2.x * a3.z) * invdet;
	matrix[1][1] = (a1.x * a3.z - a1.z * a3.x) * invdet;
	matrix[1][2] = (a2.x * a1.z - a1.x * a2.z) * invdet;
	matrix[2][0] = (a2.x * a3.y - a3.x * a2.y) * invdet;
	matrix[2][1] = (a3.x * a1.y - a1.x * a3.y) * invdet;
	matrix[2][2] = (a1.x * a2.y - a2.x * a1.y) * invdet;
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
