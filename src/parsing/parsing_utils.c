/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:42:40 by mathia            #+#    #+#             */
/*   Updated: 2023/04/21 16:28:30 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	get_instruction(char **tokens, int index, t_minirt *minirt, char *line)
{
	t_vec3	result;
	char	**xyz;

	if (tokens[index])
	{
		if (check_commas(tokens[index]))
		{
			xyz = ft_split(tokens[index], ',');
			result = ft_vec(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
			ft_free(xyz);
		}
		else
		{
			finish_gnl(minirt->fd);
			closing_fd(minirt);
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Error: Wrong n. of vector params", RED);
		}
	}
	return (result);
}

double	get_ins_double(char **tokens, int index, t_minirt *minirt, char *line)
{
	double	result;

	result = 0;
	if (tokens[index] && check_double(tokens[index]))
		result = ft_atof(tokens[index]);
	else
	{
		finish_gnl(minirt->fd);
		closing_fd(minirt);
		ft_free(tokens);
		free(line);
		error_manager(minirt, "Error: Wrong single float parameter", RED);
	}
	return (result);
}

int	tokens_number(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

void	check_scene_elem(char *line, int *al_p, int *c_p, int *l_p)
{
	if (line[0] == 'A')
		*al_p += 1;
	if (line[0] == 'C')
		*c_p += 1;
	if (line[0] == 'L')
		*l_p += 1;
}

void	manage_scene_err(t_minirt *minirt, int al_p, int c_p, int l_p)
{
	if (al_p > 1 || c_p > 1 || l_p > 1)
		error_manager(minirt, "Error: more than one A, L or, C", RED);
	else if (al_p == 0 || c_p == 0 || l_p == 0)
		error_manager(minirt, "Error: A, L or, C not present", RED);
}
