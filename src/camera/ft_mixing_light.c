/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mixing_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:46:00 by mathia            #+#    #+#             */
/*   Updated: 2023/04/19 23:24:11 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "exec.h"
#include "parsing.h"
#include "scene.h"
#include "world.h"

t_vec3  ft_mixing_light(t_vec3 *ambient_light)
{
    t_vec3  diffuse_light;
    t_vec3  mixed_light;

    diffuse_light = ft_vec(0, 0, 0);
    mixed_light = ft_vec(0, 0, 0);
    diffuse_light.x = diffuse_light.x * ALBEDO;
    diffuse_light.y = diffuse_light.y * ALBEDO;
    diffuse_light.z = diffuse_light.z * ALBEDO;
    mixed_light.x = diffuse_light.x + ambient_light->x;
    mixed_light.y = diffuse_light.y + ambient_light->y;
    mixed_light.z = diffuse_light.z + ambient_light->z;
    mixed_light.x = mixed_light.x * mixed_light.x;
    mixed_light.y = mixed_light.y * mixed_light.y;
    mixed_light.z = mixed_light.z * mixed_light.z;
    return (mixed_light);
}