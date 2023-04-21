/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alert_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:56:07 by mpagani           #+#    #+#             */
/*   Updated: 2023/04/21 12:56:24 by mpagani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	alert(char *str, char *color)
{
	int	len;
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
