/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:10:31 by iqattami          #+#    #+#             */
/*   Updated: 2024/07/01 18:22:14 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(char **tab, char c)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	count_c = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
			{
				count_c++;
			}
			j++;
		}
		i++;
	}
	return (count_c);
}
int in_map(char **t)
{
	if(ft_count(t , 'C') < 1 || ft_count(t, 'P') < 1 || ft_count(t, 'E'))
		{
			write(1, "Error\n", 6);
			return(1);
		}
	return (1);
}

void	ft_floodfill(char **tab, int x, int y, int i, int j)
{
	if (x < 0 || y < 0 || x >= i || y >= j) 
        return;
	if (tab[x][y] == '1' || tab[x][y] == 'O' )
		return;
	if(tab[x][y] == 'E' )
	{
		tab[x][y] = 'O';
		return ;
	}
		
	
	tab[x][y] = 'O';
	ft_floodfill(tab, (x + 1), y, i, j);
	ft_floodfill(tab, (x - 1), y, i, j);
	ft_floodfill(tab, x, (y + 1), i, j);
	ft_floodfill(tab, x, (y - 1), i, j);
}

void ft_check_floodfill(char **map, s_data *app)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C' || map[i][j] == 'E')
				ft_print_error("invalide map", app, 1);
			j++;
		}
		i++;
	}
}

void	ft_validate_path(char **tab, s_data *app, int len)
{
	int	x;
	int	y;
	int	k;
	char **map1;
	
	map1 = tab;
	k = ft_strlen(map1[0]);
	p_position(map1 , &x, &y);
	ft_floodfill(map1, 1, 2, len, k);
	ft_check_floodfill(map1, app);
	free_map(map1);
	exit(0);
}