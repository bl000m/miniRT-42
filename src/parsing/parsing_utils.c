/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:42:40 by mathia            #+#    #+#             */
/*   Updated: 2023/04/19 21:45:23 by mathia           ###   ########.fr       */
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

	i = 0;
	while (token[i])
	{
		if (token[i++] == ',')
			return (1);
	}
	return (0);
}

// N.B. still need to sitch the int from atoi to a double=> recode strtod
t_vec3 get_instruction(char **tokens, int index)
{
	t_vec3  result;
	char	**xyz;
	char	*ptr;

	// result = calloc(sizeof(*result), 1);
	// if (!result)
	//	 return (NULL);
	if (tokens[index])
	{
		if (check_commas(tokens[index]))
		{
			xyz = ft_split(tokens[index], ',');
			result = ft_vec(strtod(xyz[0], &ptr), strtod(xyz[1], &ptr), strtod(xyz[2], &ptr));
			ft_free(xyz);
		}
	}
	return (result);
}

double get_instruction_double(char **tokens, int index)
{
	double  result;
	char	*ptr;

	result = 0;
	if (tokens[index])
		result = strtod(tokens[index], &ptr);
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
