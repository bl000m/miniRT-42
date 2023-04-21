/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:06:52 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 13:00:56 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	free_scene(t_minirt *minirt)
{
	t_object	*temp;
	t_object	*ptr;

	temp = minirt->scene->objects;
	while (temp)
	{
		if (temp->cylinder)
			free(temp->cylinder);
		if (temp->sphere)
			free(temp->sphere);
		if (temp->plane)
			free(temp->plane);
		ptr = temp;
		temp = temp->next;
		free(ptr);
	}
	free(minirt->scene);
}

void	free_clean(t_minirt *minirt)
{
	if (minirt->scene)
		free_scene(minirt);
}

void	error_manager(t_minirt *minirt, char *message, char *color)
{
	if (message)
	{
		free_clean(minirt);
		alert(message, color);
	}
	exit (1);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
}

void	free_parsing(char **tokens, char *line)
{
	ft_free(tokens);
	free(line);
}
