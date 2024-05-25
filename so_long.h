/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:31:26 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/25 21:24:16 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include <unistd.h>
# include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>



# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif


typedef struct  Data
{
    int collect;
    int player;
    int exit;
    int enemy;
    char **map;
    int x_p;
    int y_p;
    int x_l;
    int y_l;
}s_data;


char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);
int check_borther(char **str);
int out_of_map(char **s);
int line_len(char **str);
int	ft_strlen(char *s);
char	*ft_strchr(char *str, int character);
char	*ft_strdup(char *s);
int rectangular(char **tab, int len);






#endif