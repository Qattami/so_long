/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:47:47 by iqattami          #+#    #+#             */
/*   Updated: 2024/06/28 21:32:35 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr((nb / 10));
		ft_putnbr((nb % 10));
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
    if (flag == 1)
        ft_putstr("Error\n");
    ft_putstr(str);
    free_map(point->map);
    exit(flag);
    return(1);
}