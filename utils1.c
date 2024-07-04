/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:21:43 by iqattami          #+#    #+#             */
/*   Updated: 2024/07/01 17:44:57 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void p_position(char **map, int *a, int *b)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
            {
                *a = i;
                *b = j;
            }
            j++;
        }
        i++;
    }
}
void m_moves(s_data *app)
{
    app->moves++;
    write(1, "Move number:",12);
    ft_putnbr(app->moves);
    write(1, "\n", 1);
    return ;
}

void c_number(s_data *app)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while(app->map[i])
    {
        j = 0;
        while(app->map[i][j])
        {
            if(app->map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    app->c = count;
}

void change_player_position(s_data *app)
{
    int a;
    int b;
    
    a = 0;
    b = 0;
    c_number(app);
    p_position(app->map, &a, &b);
    if(app->map[a + app->x_p][b + app->y_p] == '1')
        return;
  
    if(app->map[a + app->x_p][b + app->y_p] == 'C')
        m_moves(app);
    if(app->map[a + app->x_p][b + app->y_p] == 'E' && app->c == 0 )
    {
        m_moves(app);
        ft_print_error("Congrats!! you won ! 🥳", app, 0);
    }
      if(app->map[a + app->x_p][b + app->y_p] == 'E' && app->c != 0)
        return;
    app->map[a][b] = '0';
    app->map[a + app->x_p][b + app->y_p] = 'P';
    mlx_clear_window(app->mlx, app->win);
    if(app->x_p != 0 || app->y_p != 0)
        m_moves(app);
}
int handle_keys(int keycode, s_data *app)
{
    app->x_p = 0;
    app->y_p = 0;
    if (keycode == 65307) // ESC key
        ft_print_error("You exit my game 🙄\n", app, 0);
    if (keycode == 65362 || keycode == 119) // Up arrow or 'W' key
        app->x_p = -1;
    if (keycode == 65364 || keycode == 115) // Down arrow or 'S' key
        app->x_p = 1;
    if (keycode == 65363 || keycode == 100) // Right arrow or 'D' key
        app->y_p = 1;
    if (keycode == 65361 || keycode == 97) // Left arrow or 'A' key
        app->y_p = -1;
    change_player_position(app);
   
    draw_map(app);
    return (0);
}


