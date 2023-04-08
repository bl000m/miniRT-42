/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathia <mathia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:42:40 by mathia            #+#    #+#             */
/*   Updated: 2023/04/08 20:01:42 by mathia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"

void    add_new_object(t_minirt *minirt, void *new_object_content)
{
    t_object    *temp;
    t_object    *new_object;

    if (!new_object_content)
        return ;
    new_object = calloc(sizeof(*new_object), 1);
    if (new_object == NULL)
        return ;
    temp = minirt->scene->objects;
    while (temp)
        temp = temp->next;
    if (!temp->content)
    {
        temp->content = new_object_content;
        free(new_object);
    }
    else
    {
        temp->next = new_object;
        new_object->content = new_object_content;
        new_object->next = NULL;
    }
}
int    check_commas(char *token)
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
    t_vec3  *result;
    char    **xyz;
    char    *ptr;

    result = calloc(sizeof(*result), 1);
    // if (!result)
    //     return (NULL);
    if (tokens[index])
    {
        if (check_commas(tokens[index]))
        {
            xyz = ft_split(tokens[index], ',');
            *result = ft_vec(strtod(xyz[0], &ptr), strtod(xyz[1], &ptr), strtod(xyz[2], &ptr));
        }
    }
    return (*result);
}

double get_instruction_double(char **tokens, int index)
{
    double  result;
    char    *ptr;

    result = 0;
    if (tokens[index])
        result = strtod(tokens[index], &ptr);
    return (result);
}