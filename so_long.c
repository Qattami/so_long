/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:31 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/31 15:23:57 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int protection(char **tab, int len)
{
    if(!tab)
        return (write(1, "map is empty", 12), 1);
    if(line_len(tab, len) == 1)
        return (write(1, "Lines are not equal", 19), 1);
    if(check_border(tab, len - 1) == 1)
        return (write(1, "border error", 13));   
    if(out_of_map(tab, len - 1))
        return (write(1, "invalide character", 18), 1);
    
    if(rectangular(tab, len - 1))
        return(write(1, "the map is not rectangular", 26), 1);
    return(0);
}
void	ft_str_replace(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
}

int main(int ac, char **av)
{
    void *ptr;
    void *win;
    if(ac == 2)
    {
         s_data data;

        int len;
        int c;
        char *tmp;
        int i;

        i = 0;
        len = 0;
        c = open(av[1], O_RDONLY);
        if(c < 1)
            exit(1);
        tmp = get_next_line(c);
        if(!tmp)
            return (1);
        while (tmp)
        {
            len++;
            tmp = get_next_line(c);
        }
        char **tab = malloc(sizeof(char *) * len + 1);
        if(!tab)
            exit(1);
        close(c);
        c = open(av[1], O_RDONLY);
        if(c < 1)
            exit(1);
        while (len > i)
        {
            tab[i] = get_next_line(c);
            ft_str_replace(tab[i++], '\n', '\0');
        }
            
        if(protection(tab, len) == 1)
            write(1, "error\n", 6);
        
        // ft_validate_path(tab, len);
        // protection(tab, len);
        // ft_validate_path(tab, len);
        //  ptr = mlx_init();
        //  win = mlx_new_window(ptr, 500, 600,
		// 	"so_long!");
        //     mlx_loop(ptr);
        
    }
}