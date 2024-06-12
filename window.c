/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:40:57 by iqattami          #+#    #+#             */
/*   Updated: 2024/06/13 00:58:04 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(s_data *point)
{
    int h;
    int w;
    point->player = mlx_file_to_image(point->mlx, "bubu0.xpm", &h, &w);
    if(!(point->player))
        ft_print_error("player can't load \n", point, 1);
    point->wall = mlx_file_to_image(point->mlx, "wall.xpm", &h, &w);
    if(!(point->wall))
        ft_print_error("wall can't load \n", point, 1);
    point->burger = mlx_file_to_image(point->mlx, "burger.xpm", &h, &w);
    if(!(point->burger))
        ft_print_error("burger can't load \n", point, 1);
    point->ground = mlx_file_to_image(point->mlx, "ground.xpm", &h, &w);
    if(!(point->ground))
        ft_print_error("ground can't load \n", point, 1);
    point->exit = mlx_file_to_image(point->mlx, "exit.xpm", &h, &w);
    if(!(point->exit))
        ft_print_error("exit can't load \n", point, 1);    
}