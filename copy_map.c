/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:45:59 by iqattami          #+#    #+#             */
/*   Updated: 2024/07/06 16:01:32 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(char **tab, int len)
{
   char **map;
    int i;

    map = malloc(sizeof(char *) * (len + 1));
    if (!map)
        return (NULL);
    i = 0;
    while (i < len)
    {
        map[i] = ft_strdup(tab[i]);
        if (!map[i])
        {
            while (--i >= 0)
                free(map[i]);
            free(map);
            return (NULL);
        }
        i++;
    }
    map[len] = NULL;
    return (map);
}