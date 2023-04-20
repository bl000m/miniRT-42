/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:42:40 by mathia            #+#    #+#             */
/*   Updated: 2023/04/20 22:01:52 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"

void	add_new_plane_object(t_minirt *minirt, t_plane *new_object_content)
{
	t_object	*temp;
	t_object	*new_object;

	if (!new_object_content)
		return ;
	temp = minirt->scene->objects;
	while (temp->next)
		temp = temp->next;
	if (!temp->first)
	{
		temp->plane = new_object_content;
		temp->type = 'p';
		temp->first = 1;
	}
	else
	{
		new_object = calloc(sizeof(*new_object), 1);
		if (new_object == NULL)
			return ;
		new_object->plane = new_object_content;
		new_object->first = 1;
		new_object->next = NULL;
		new_object->type = 'p';
		temp->next = new_object;
	}
}

void	add_new_sphere_object(t_minirt *minirt, t_sphere *new_object_content)
{
	t_object	*temp;
	t_object	*new_object;

	if (!new_object_content)
		return ;
	temp = minirt->scene->objects;
	while (temp->next)
		temp = temp->next;
	if (!temp->first)
	{
		temp->sphere = new_object_content;
		temp->type = 's';
		temp->first = 1;
	}
	else
	{
		new_object = calloc(sizeof(*new_object), 1);
		if (new_object == NULL)
			return ;
		new_object->sphere = new_object_content;
		new_object->first = 1;
		new_object->type = 's';
		new_object->next = NULL;
		temp->next = new_object;
	}
}

void	add_new_cylinder_object(t_minirt *minirt, t_cylinder *new_object_content)
{
	t_object	*temp;
	t_object	*new_object;

	if (!new_object_content)
		return ;
	temp = minirt->scene->objects;
	while (temp->next)
		temp = temp->next;
	if (!temp->first)
	{
		temp->cylinder = new_object_content;
		temp->type = 'c';
		temp->first = 1;
	}
	else
	{
		new_object = calloc(sizeof(*new_object), 1);
		if (new_object == NULL)
			return ;
		new_object->cylinder = new_object_content;
		new_object->first = 1;
		new_object->type = 'c';
		new_object->next = NULL;
		temp->next = new_object;
	}
}

int	check_commas(char *token)
{
	int i;
	int	count;

	count = 0;
	i = 0;
	while (token[i])
	{
		if (token[i++] == ',')
		{
			count++;
		}
	}
	if (count == 2)
		return (1);
	return (0);
}

// N.B. still need to sitch the int from atoi to a double=> recode ft_atof
t_vec3 get_instruction(char **tokens, int index, t_minirt *minirt)
{
	t_vec3  result;
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
			error_manager(minirt, "Error: Wrong number of params for a vector", RED);
	}
	return (result);
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
		if ((token[i] >= '0' && token[i] <= '9') || token[i] == '.' || token[i] == '\n')
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

double get_instruction_double(char **tokens, int index, t_minirt *minirt)
{
	double  result;

	result = 0;
	if (tokens[index] && check_double(tokens[index]))
		result = ft_atof(tokens[index]);
	else
		error_manager(minirt, "Error: Wrong single float parameter", RED);
	return (result);
}

int	check_parameters(t_vec3 vector)
{
	if (vector.x == 0 && vector.y == 0 && vector.z == 0)
		return (1);
	return (0);
}

void alert(char *str, char *color)
{
    int len;
	int	i;

	i = 0;
	len = ft_strlen(str);
    printf("╭─");
	while (i < len)
	{
		printf("-");
		i++;
	}
    printf("─╮\n");
	printf("│ %s%s%s │\n", color, str, NORMAL);
	printf("╰─");
	i = 0;
	while (i < len)
	{
		printf("─");
		i++;
	}
	printf("─╯\n");
}

int	tokens_number(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		i++;
	}
	return (i);
}

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