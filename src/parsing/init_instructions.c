/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:36:05 by mathia            #+#    #+#             */
/*   Updated: 2023/04/08 13:51:28 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "world.h"

void    initialize_plane(t_minirt *minirt, char **tokens)
{
    t_plane *new_plane;

    new_plane = ft_calloc(sizeof(*new_plane), 1);
    if (new_plane == NULL)
        return ;
    new_plane->pos = get_instruction(tokens, 1);
    new_plane->dir = get_instruction(tokens, 2);
    new_plane->color = get_instruction(tokens, 3);
    add_new_object(minirt, new_plane, "t_plane");
}

void    initialize_sphere(t_minirt *minirt, char **tokens)
{
    t_sphere *new_sphere;

    new_sphere = ft_calloc(sizeof(*new_sphere), 1);
    if (new_sphere == NULL)
        return ;
    new_sphere->center = get_instruction(tokens, 1);
    new_sphere->diameter = get_instruction(tokens, 2);
    new_sphere->color = get_instruction(tokens, 3);
    add_new_object(minirt, new_sphere, "t_sphere");
}

void    initialize_cylinder(t_minirt *minirt, char **tokens)
{
    t_cylinder *new_cylinder;

    new_cylinder = ft_calloc(sizeof(*new_cylinder), 1);
    if (new_cylinder == NULL)
        return ;
    new_cylinder->center = get_instruction(tokens, 1);
    new_cylinder->dir = get_instruction(tokens, 2);
    new_cylinder->diameter = get_instruction(tokens, 3);
    new_cylinder->height = get_instruction(tokens, 4);
    new_cylinder->color = get_instruction(tokens, 5);
    add_new_object(minirt, new_cylinder, "t_cylinder");
}

void    initialize_ambient_light(t_minirt *minirt, char **tokens)
{
    t_ambient *ambient_light;

    ambient_light = ft_calloc(sizeof(*ambient_light), 1);
    if (ambient_light == NULL)
        return ;
    ambient_light->ratio = get_instruction(tokens, 1);
    ambient_light->color = get_instruction(tokens, 2);
    minirt->ambient_light = ambient_light;
}

void    initialize_camera(t_minirt *minirt, char **tokens)
{
    t_camera *camera;

    camera = ft_calloc(sizeof(*camera), 1);
    if (camera == NULL)
        return ;
    camera->view_point = get_instruction(tokens, 1);
    camera->orientation = get_instruction(tokens, 2);
    camera->FOV = get_instruction(tokens, 3);
    minirt->camera = camera;
}

void    initialize_light(t_minirt *minirt, char **tokens)
{
    t_light *light;

    light = ft_calloc(sizeof(*light), 1);
    if (light == NULL)
        return ;
    light->pos = get_instruction(tokens, 1);
    light->ratio = get_instruction(tokens, 2);
    light->color = get_instruction(tokens, 3);
    minirt->light = light;
}