/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:31 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/19 16:12:17 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    if(ac > 1)
    {
        s_data data;

        int len;
        int c;
        char tmp;

        c = open("file.txt", O_RDONLY);
        tmp = get_next_line(c);
        if(!tmp)
            return (1);
        while (tmp)
        {
            len++;
            tmp = get_next_line(c);
            free(tmp);
        }
        
    }
}