/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checking_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:45:25 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/24 14:53:31 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	checking_id(t_minirt *minirt, char **tokens, int *error, char *line)
{
	if (check_params_err(tokens))
	{
		if (ft_strncmp(tokens[0], "pl", 2) == 0 && !tokens[0][2])
			*error += initialize_plane(minirt, tokens, line);
		if (ft_strncmp(tokens[0], "sp", 2) == 0 && !tokens[0][2])
			*error += initialize_sphere(minirt, tokens, line);
		if (ft_strncmp(tokens[0], "cy", 2) == 0 && !tokens[0][2])
			*error += initialize_cylinder(minirt, tokens, line);
		if (ft_strncmp(tokens[0], "A", 1) == 0 && !tokens[0][1])
			*error += initialize_ambient_light(minirt, tokens, line);
		if (ft_strncmp(tokens[0], "C", 1) == 0 && !tokens[0][1])
			*error += initialize_camera(minirt, tokens, line);
		if (ft_strncmp(tokens[0], "L", 1) == 0 && !tokens[0][1])
			*error += initialize_light(minirt, tokens, line);
	}
	else
	{
		finish_gnl(minirt->fd);
		closing_fd(minirt);
		ft_free(tokens);
		free(line);
		error_manager(minirt, "Error: something wrong in .rt file", INFO);
	}
}

int	check_capital(char c)
{
	return (c >= 65 && c <= 90 && (c == 'C' || c == 'L' || c == 'A'));
}

void	elem_id_scenario(t_minirt *minirt, char **tokens, char *line)
{
	if (tokens[0][0] >= 65 && tokens[0][0] <= 90)
	{
		if (!check_capital(tokens[0][0])
		|| (check_capital(tokens[0][0]) && tokens[0][1]))
		{
			finish_gnl(minirt->fd);
			closing_fd(minirt);
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Error: Scene element type id error", RED);
		}
	}
}

void	object_id_scenario(t_minirt *minirt, char **tokens, char *line)
{
	if (tokens[0][0] >= 97 && tokens[0][0] <= 122)
	{
		if (check_object_id(tokens[0]))
		{
			finish_gnl(minirt->fd);
			closing_fd(minirt);
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Error: object type identifier error", RED);
		}
	}
}

void	commas_scenario(t_minirt *minirt, char **tokens, char *line, int i)
{
	int	j;

	j = 0;
	while (tokens[i][j])
	{
		if (tokens[i][j] == ',' && (j == 0
			|| tokens[i][j + 1] < '0' || tokens[i][j + 1] > '9')
			&& (tokens[i][j + 1] != '-'))
		{
			finish_gnl(minirt->fd);
			closing_fd(minirt);
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Error: too much commas in params", RED);
		}
		j++;
	}
	j = 0;
}
