/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:21 by iqattami          #+#    #+#             */
/*   Updated: 2024/06/28 17:36:17 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int rectangular(char **tab, int len)
{
    if(ft_strlen(tab[0]) == len)
        return(1);
    return(0);
}
int check_border(char **str ,int len_get)
{
    int i;
    int len;
    int j;

    i = -1;
    len = ft_strlen(str[0]);
      j = -1;
      i = -1;
    printf("%d\n",len_get);
    printf("%d\n",len);

    while(++i < len_get )
        if(str[i][0] != '1')
            return(1);
    i = -1; 
    while (++i < len_get)
        if(str[i][len - 1] != '1')
            return(1);
    while(++j < len - 2)
        if(str[0][j] != '1')
            return (1);
    j = -1;
    while (++j < len - 2)
        if (str[len_get - 1][j] != '1')
            return (1);
    return (0);
}

int out_of_map(char **s, int len)
{
    int i;
    int j;

    i = 0;
    while(i < len)
    {
        j = 0;
        while(s[i][j])
        {
            if(s[i][j] != '1' && s[i][j] != '0' && s[i][j] != 'C' && s[i][j] != 'E' && s[i][j] != 'P')
                return(1);
            j++;
        }
        i++;
    }
    return (0);
}

int line_len(char **str ,int len)
{
    int i;

    i = 0;
    while((len - 1) > i)
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

