/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:14:07 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 10:14:48 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static inline void	treat_decimal_part(const char *nptr, double *result)
{
	ssize_t	nbr_decimal;

	if (*nptr == '.')
	{
		nbr_decimal = 0;
		nptr++;
		while (ft_isdigit(*nptr))
		{
			*result = *result * 10 + (*nptr++ - '0');
			nbr_decimal--;
		}
		while (nbr_decimal++ < 0)
			*result /= 10;
	}
}

double	ft_atof(char *nptr)
{
	double	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - '0');
	treat_decimal_part(nptr, &result);
	return (result * sign);
}
