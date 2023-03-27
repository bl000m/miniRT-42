/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:28:19 by sasha             #+#    #+#             */
/*   Updated: 2023/03/27 13:43:53 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_node	*ft_new_sphere(t_vec3 cent, double r)
{
	t_sphere	*sphere;
	t_node		*node;

	sphere = malloc(sizeof(t_sphere));
	node = malloc(sizeof(t_node));
	if (sphere == NULL || node == NULL)
	{
		(void) (write(2, "malloc fails\n", 13) + 1);
		free(sphere);
		free(node);
		return (NULL);
	}
	sphere->center = cent;
	sphere->radius = r;
	node->type = SPH;
	node->hittable = sphere;
	node->next = NULL;
	return (node);
}

/*
	Add new node at the begining of the list
*/
void	ft_add_node(t_node **head, t_node *node)
{
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	node->next = *head;
	*head = node;
	return ;
}

void	ft_del_lst(t_node **head)
{
	t_node	*node;
	t_node	*next;

	node = *head;
	while (node)
	{
		next = node->next;
		free(node->hittable);
		free(node);
		node = next;
	}
	*head = NULL;
}
