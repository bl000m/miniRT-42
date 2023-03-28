/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:54:35 by sasha             #+#    #+#             */
/*   Updated: 2023/03/28 22:33:09 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
	Camera is at origin (0, 0, 0), facing (0, 0, -1)
	The x-axis points right, the y-axis points up,
	and the z-axis points toward the back of the camera
	(meaning every camera ray will have negative z)
	canvas is positioned at (x, y, -1)
	PS. the x and y in the parameter is the offset of pixel
	with the top left corner be (0, 0)
*/
t_ray	ft_camera_ray(t_canvas *canvas, int x, int y)
{
	t_ray	temp;

	temp.orig.x = 0;
	temp.orig.y = 0;
	temp.orig.z = 20;
	temp.dir.x = (canvas->pos.x + canvas->eps * x) - temp.orig.x;
	temp.dir.y = canvas->pos.y + canvas->eps * (HEIGHT - y) - temp.orig.y;
	temp.dir.z = canvas->pos.z - temp.orig.z;
	temp.dir = ft_unit_vec(temp.dir);
	return (temp);
}
