/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:21 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/29 16:46:26 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int rectangular(char **tab, int len)
{
    int i;

    i = 0;
    while(tab[i])
    {
        if(ft_strlen(tab[i++]) <= len)
            return(1);
    }
    return (0);
}
int check_border(char **str ,int len_get)
{
    int i;
    int len;
    int clen;
    int j;

    i = 0;
    j = 0;
    len = ft_strlen(str[0]);
    clen = len;
    // printf("hhh ---->%d\n",len_get);
    // while(i > len && clen > 0)
    // {
    //     if(str[0][i] != 1 || str[len_get][clen] != 1)
    //         return (1);
    //     i++;
    //     clen--; 
    // }
    
    while(str[i])
    {
        printf("--> %s",str[i]);
        i++;
    }
    i = 0;
    while(str[i])
    {
        if(str[i][0] != 1 && str[i][ft_strlen(str[i]) - 2] != 1)
        {
            printf("hii\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int out_of_map(char **s)
{
    int i;
    int j;

    i = 0;
    while(s[i])
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

// void flood_fill(int pos_x, int pos_y, int target_color, int color)
// {
  
//    if( || a[pos_x][pos_y] == 1 ) // if there is no wall or if i haven't been there
//       return;                                              // already go back
   
//    if(a[pos_x][pos_y] != target_color) // if it's not color go back
//       return;
   
//    a[pos_x][pos_y] = color; // mark the point so that I know if I passed through it. 
   
//    flood_fill(pos_x + 1, pos_y, color);  // then i can either go south
//    flood_fill(pos_x - 1, pos_y, color);  // or north
//    flood_fill(pos_x, pos_y + 1, color);  // or east
//    flood_fill(pos_x, pos_y - 1, color);  // or west
   
//    return;

// }

