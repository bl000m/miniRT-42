/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:01:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/20 16:07:55 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "world.h"
#include "camera.h"
#include "mlx.h"
#include "exec.h"

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

void	checking_identifier(t_minirt *minirt, char **tokens, int *error, char *line)
{
	printf("tokens[0] = %s check_params = %d\n", tokens[0], check_params_err(tokens));
	if (check_params_err(tokens))
	{
		if (ft_strncmp(tokens[0], "pl", 2) == 0 && !tokens[0][2])
			*error += initialize_plane(minirt, tokens);
		if (ft_strncmp(tokens[0], "sp", 2) == 0 && !tokens[0][2])
			*error += initialize_sphere(minirt, tokens);
		if (ft_strncmp(tokens[0], "cy", 2) == 0 && !tokens[0][2])
			*error += initialize_cylinder(minirt, tokens);
		if (ft_strncmp(tokens[0], "A", 1) == 0 && !tokens[0][1])
			*error += initialize_ambient_light(minirt, tokens);
		if (ft_strncmp(tokens[0], "C", 1) == 0 && !tokens[0][1])
			*error += initialize_camera(minirt, tokens);
		if (ft_strncmp(tokens[0], "L", 1) == 0 && !tokens[0][1])
			*error += initialize_light(minirt, tokens);
	}
	else
	{
		ft_free(tokens);
		free(line);
		error_manager(minirt, "Error in the instruction file", INFO);
	}
}

int	check_capital(char c)
{
	return (c >= 65 && c <= 90 && (c == 'C' || c == 'L' || c == 'A'));
}

int	check_object_id(char *token)
{
	return (!ft_strncmp(token, "sp", 2) && !ft_strncmp(token, "pl", 2)
		&& !ft_strncmp(token, "cy", 2));
}

int	check_numeric(char *token)
{
	int	i;
	int	res;

	i = 0;
	while (token[i])
	{
		if ((token[i] >= '0' && token[i] <= '9') || token[i] == '\n'
			|| token[i] == ',' || token[i] == '.' || token[i] == '-')
			res = 1;
		else
			return (0);
		i++;
	}
	return (res);
}


void	check_tokens(char **tokens, t_minirt *minirt, char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (tokens[0][0] >= 65 && tokens[0][0] <= 90)
	{
		if (!check_capital(tokens[0][0])
		|| (check_capital(tokens[0][0]) && tokens[0][1]))
		{
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Scene element type identifier error", RED);
		}
	}
	if (tokens[0][0] >= 97 && tokens[0][0] <= 122)
	{
		if (check_object_id(tokens[0]))
		{
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Object type identifier error", RED);
		}
	}
	while (tokens[i])
	{
		// printf("token = %s - check_num = %d\n", tokens[i], check_numeric(tokens[i]));
		if (!check_numeric(tokens[i]))
		{
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Error: char not allowed in parameters", RED);
		}
		while (tokens[i][j])
		{

			if (tokens[i][j] == ',' && (j == 0 || tokens[i][j + 1] < '0' || tokens[i][j + 1] > '9')
				&& (tokens[i][j + 1] != '-'))
			{
				ft_free(tokens);
				free(line);
				error_manager(minirt, "too much commas in params", RED);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	read_rt_map(char *source, t_minirt *minirt, int *error)
{
	char	*line;
	int		fd;
	int		n_line;
	char	**tokens;

	n_line = 0;
	get_size(source, minirt);
	fd = open_file_map(source, minirt);
	while (n_line < minirt->rt_map.n_lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tokens = ft_split(line, ' ');
		if (!tokens)
			error_manager(minirt, "Please remove spaces in empty line", RED);
		check_tokens(tokens, minirt, line);
		checking_identifier(minirt, tokens, error, line);
		ft_free(tokens);
		free(line);
		n_line++;
	}
	if (close(fd) < 0)
		error_manager(minirt, "Error in closing FD", RED);
	return (*error);
}
