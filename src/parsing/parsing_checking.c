/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:40:54 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 15:55:23 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	check_commas(char *token)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (token[i])
	{
		if (token[i++] == ',')
			count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int	check_double(char *token)
{
	int	i;
	int	res;
	int	count;

	count = 0;
	i = 0;
	while (token[i])
	{
		if ((token[i] >= '0' && token[i] <= '9')
			|| token[i] == '.' || token[i] == '\n')
		{
			if (token[i] == '.')
				count++;
			res = 1;
		}
		else
			return (0);
		i++;
	}
	if (count <= 1)
		return (1);
	else
		return (0);
	return (res);
}

int	check_parameters(t_vec3 vector)
{
	if (vector.x == 0 && vector.y == 0 && vector.z == 0)
		return (1);
	return (0);
}

int	check_params_err(char **tokens)
{
	if (ft_strncmp(tokens[0], "pl", 2) == 0 && !tokens[0][2])
		return (tokens_number(tokens) == 4);
	if (ft_strncmp(tokens[0], "sp", 2) == 0 && !tokens[0][2])
		return (tokens_number(tokens) == 4);
	if (ft_strncmp(tokens[0], "cy", 2) == 0 && !tokens[0][2])
		return (tokens_number(tokens) == 6);
	if (ft_strncmp(tokens[0], "A", 1) == 0 && !tokens[0][1])
		return (tokens_number(tokens) == 3);
	if (ft_strncmp(tokens[0], "C", 1) == 0 && !tokens[0][1])
		return (tokens_number(tokens) == 4);
	if (ft_strncmp(tokens[0], "L", 1) == 0 && !tokens[0][1])
		return (tokens_number(tokens) == 4);
	if (ft_strncmp(tokens[0], "\n", 1) == 0 && !tokens[0][1])
		return (1);
	return (0);
}

void	check_quality_token(t_minirt *minirt, char **tokens)
{
	if (!tokens)
	{
		closing_fd(minirt);
		error_manager(minirt, "Error: unnecessary spaces in line", RED);
	}
}
