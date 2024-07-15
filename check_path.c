/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:10:31 by iqattami          #+#    #+#             */
/*   Updated: 2024/07/15 01:13:05 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_count(s_data *app)
{
    app->c = 0;
    app->p = 0;
	app->e = 0;

	int i;
	int j;

	i = 0;

    while (app->map[i] != NULL) {
        j = 0;
		 
        while (app->map[i][j] != '\0') {
            if (app->map[i][j] == 'C') 
                app->c++;
            else if (app->map[i][j] == 'P') 
                app->p++;
			else if (app->map[i][j] == 'E') 
                app->e++;
            j++;
        }
        i++;
    }
}

int in_map(s_data *app)
{
	ft_count(app);	
    if(app->c < 1 || app->p != 1 || app->e != 1)
    {
        return(1);
    }
    return (0);
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

void	ft_validate_path(s_data *app, int len)
{
	int	x;
	int	y;
	int	k;
	 char **map1;
	
	 map1 = copy_map(app->map, len);
	k = ft_strlen(app->map[0]);
	p_position(map1 , &x, &y);
	ft_floodfill(map1, 1, 2, len, k);
	ft_check_floodfill(map1, app);
	 free_map(map1);
}