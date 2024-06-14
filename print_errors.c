/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:47:47 by iqattami          #+#    #+#             */
/*   Updated: 2024/06/14 03:00:05 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.c"

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void free_map(char **map)
{
    int i;
    
    i= 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int ft_print_error(char *str, s_data *point, int flag)
{
    ft_putstr("Error\n");
    ft_putstr(str);
    free_map(point->map);
    exit(flag);
    return(1);
}