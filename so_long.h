/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:31:26 by iqattami          #+#    #+#             */
/*   Updated: 2024/07/01 17:51:29 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include <unistd.h>
# include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif


typedef struct  Data
{
    int c;
    int enemy;
    char **map;
    int x_p;
    int y_p;
    int moves;
    void	*mlx;
	void	*win;
	void	*wall;
	void	*ground;
	void	*burger;
	void	*player;
	void	*exit;
}s_data;


char	*ft_strjoin1(char *s1, char *s2);
int check_border(char **str ,int len_get);
int out_of_map(char **s, int len);
int line_len(char **str, int len);
int	ft_strlen(char *s);
char	*ft_strchr(char *str, int character);
char	*ft_strdup(char *s);
int rectangular(char **tab, int len);
void	ft_validate_path(char **tab, s_data *app, int len);
char	*get_next_line(int fd);
int ft_print_error(char *str, s_data *point, int flag);
void draw_map(s_data *point);
void load_images(s_data *point);
void	ft_str_replace(char *str, char c1, char c2);
int	handle_keys(int keycode, s_data *app);
void free_map(char **map);
void	ft_putnbr(int n);
int update_animation(s_data *app);
int	ft_count(char **tab, char c);
void p_position(char **map, int *a, int *b);
int in_map(char **t);








#endif