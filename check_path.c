/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:10:31 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/29 16:15:44 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void ft_error(int fd)
{
	write(fd,"path error", 10);
	exit(1);
}
int	ft_count_c(char **tab, int len)
{
	int	x;
	int	y;
	int	x_l;
	int	count_c;

	y = 0;
	count_c = 0;
	x_l = ft_strlen(tab[0]);
	while (y < len)
	{
		x = 0;
		while (x < x_l)
		{
			if (tab[y][x] == 'C')
			{
				count_c++;
			}
			x++;
		}
		y++;
	}
	return (count_c);
}

void	ft_floodfill(char**tab, int x, int y, int *count_c, int *e, int i, int j)
{
	if (x <= 0 || x >= i || y <= 0 || y >= j
		|| tab[y][x] == '1' || tab[y][x] == 'c'
		|| tab[y][x] == 'o' || tab[y][x] == 'e'
		|| tab[y][x] == 'E')
	{
		if (tab[y][x] == 'E')
			*e = 1;
		return ;
	}
	if (tab[y][x] == 'C')
	{
		(*count_c)--;
		tab[y][x] = 'c';
	}
	else if (tab[y][x] == '0')
		tab[y][x] = 'o';
	ft_floodfill(tab, x, (y + 1), count_c, e, i, j);
	ft_floodfill(tab, x, (y - 1), count_c, e, i, j);
	ft_floodfill(tab, (x + 1), y, count_c, e, i, j);
	ft_floodfill(tab, (x - 1), y, count_c, e, i, j);
}



void	ft_validate_path(char **tab, int len)
{
	int	x;
	int	y;
	int	count_c;
	int *e;
	y = 0;
	*e = 0;
	int i;
	
	count_c = ft_count_c(tab, len);
	i = ft_strlen(tab[0]);
	while (y < len)
	{
		x = 0;
		while (x < i)
		{
			if (tab[y][x] == 'P')
			{
				ft_floodfill(tab, x, y, &count_c, e, i, len);
				if (count_c != 0)
					ft_error(1);
				if (*e == 0)
					ft_error(1);
				return ;
			}
			x++;
		}
		y++;
	}
	write(1, "ok\n", 3);
}