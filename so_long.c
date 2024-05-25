/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:31 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/25 21:28:18 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int protection(char **tab, int len)
{
    if(!tab)
        return (write(1, "map is empty", 12), 1);
    // if(check_borther(tab))
    //     return (write(1, "borther error", 13));   
    if(out_of_map(tab))
        return (write(1, "invalide character", 18), 1);
    if(line_len(tab))
        return (write(1, "Lines are not equal", 19), 1);
    if(rectangular(tab, len))
        return(write(1, "the map is not rectangular", 26), 1);
    return(0);
}

int main(int ac, char **av)
{
    // (void) **av;
    // (void) ac;
    if(ac == 2)
    {
        // s_data data;

        int len;
        int c;
        char *tmp;
        int i;

        i = 0;
        len = 0;
        c = open(av[1], O_RDONLY);
        tmp = get_next_line(c);
        if(!tmp)
            return (1);
        while (tmp)
        {
            len++;
            tmp = get_next_line(c);
        }
        char **tab = malloc(sizeof(char) * len + 1);
        if(!tab)
            exit(1);
        c = open(av[1], O_RDONLY);
        while (len > i)
            tab[i++] = get_next_line(c);
        protection(tab, len);
        
    }
}