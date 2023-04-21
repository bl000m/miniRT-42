/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:01:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 16:56:43 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	check_filename(char *file_map, t_minirt *minirt)
{
	int	size;

	size = ft_strlen(file_map);
	if (ft_strncmp(&file_map[size - 3], ".rt", 3))
		error_manager(minirt, "Error: needed .rt file", RED);
}

int	read_rt_map(char *source, t_minirt *minirt, int *error)
{
	char	*line;
	int		n_line;
	char	**tokens;

	minirt->fd = 0;
	n_line = 0;
	check_filename(source, minirt);
	get_size(source, minirt);
	open_file_map(source, minirt);
	line = NULL;
	while (1)
	{
		line = get_next_line(minirt->fd);
		if (!line)
			break ;
		tokens = ft_split(line, ' ');
		check_quality_token(minirt, tokens);
		check_tokens(tokens, minirt, line);
		checking_id(minirt, tokens, error, line);
		free_parsing(tokens, line);
		n_line++;
	}
	closing_fd(minirt);
	return (*error);
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
		{
			if ((token[i] == '-' && (token[i + 1] < '0' || token[i + 1] > '9'))
				|| (token[i] == '.' && (token[i + 1] < '0'
						|| token[i + 1] > '9')))
				return (0);
			res = 1;
		}
		else
			return (0);
		i++;
	}
	return (res);
}

void	check_tokens(char **tokens, t_minirt *minirt, char *line)
{
	int	i;

	i = 1;
	elem_id_scenario(minirt, tokens, line);
	object_id_scenario(minirt, tokens, line);
	while (tokens[i])
	{
		if (!check_numeric(tokens[i]))
		{
			finish_gnl(minirt->fd);
			closing_fd(minirt);
			ft_free(tokens);
			free(line);
			error_manager(minirt, "Error: something wrong in parameters", RED);
		}
		commas_scenario(minirt, tokens, line, i);
		i++;
	}
}
