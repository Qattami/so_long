/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:21 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/17 18:34:04 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_borther(char **str)
{
    int i;
    int len;
    int clen;
    int j;

    i = 0;
    j = 0;
    len = ft_strlen(str[0]);
    clen = len;
    
    while(i > len && clen > 0)
    {
        if(str[0][i] != 1 || str[len][clen] != 0)
            return (1);
        i++;
        clen--; 
    }
    i = 0;
    while(str[0][j])
    {
        if(str[0][j] != 1 || str[len][j] != 1)
            return (1);
        j++;
    }
    return (0);
}

int out_of_map(char **s)
{
    int i;
    int j;

    i = 0;
    while(s[i][j])
    {
        j = 0;
        while(s[i][j])
        {
            if(s[i][j] != 1 && s[i][j] != 0 && s[i][j] != 'C' && s[i][j] != 'E' && s[i][j] != 'P')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int line_len(char **str)
{
    int i;

    i = 1;
    while(str[i])
    {
        if(ft_strlen(str[0]) != ft_strlen(str[i]))
            return (1);
        i++;
    }
    return (0);
}


