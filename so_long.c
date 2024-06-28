/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:31 by iqattami          #+#    #+#             */
/*   Updated: 2024/06/28 17:39:06 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int protection_1(char **tab, int len)
{
    if(!tab)
        return (write(1, "map is empty", 12), 1);
    if(line_len(tab, len) == 1)
        return (write(1, "Lines are not equal", 19), 1);
    if(check_border(tab, len) == 1)
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
int	exit_game(s_data *app)
{
	ft_print_error("You exit my game 🙄", app, 0);
	return (0);
}
int get_len(char *str)
{
    int len;
    int c;
    char *tmp;

    len = 0;
    c = open(str, O_RDONLY);
    if(c < 1)
        exit(1);
    tmp = get_next_line(c);
    if(!tmp)
        return (1);
    while (tmp)
    {
        len++;
        tmp = get_next_line(c);
        free(tmp);
    }
    close(c);
    free(tmp);
    return (len);
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        s_data app;
        int len;
        int c;
        int i;

        i = 0;
        len = get_len(av[1]);
        char **tab = malloc(sizeof(char *) * len + 1);
        if(!tab)
            exit(1);
        
        c = open(av[1], O_RDONLY);
        if(c < 1)
            exit(1);
        while (len > i)
        {
            
            tab[i] = get_next_line(c);
            ft_str_replace(tab[i++], '\n', '\0');
        }
            
        if(protection_1(tab, len) == 1)
            write(1, "error\n", 6);
         app.map = tab;
        //  free_map(tab);
         app.mlx = mlx_init();
         load_images(&app);
         app.win = mlx_new_window(app.mlx, ft_strlen(tab[0]) * 30, len * 30, "so_long!");
         draw_map(&app);
         app.moves = 0;
        mlx_hook(app.win, 02, 1L << 17, exit_game, &app);
        mlx_hook(app.win, 02, 1L<<0, handle_keys, &app);
        mlx_loop(app.mlx);
        mlx_destroy_window(app.mlx, app.win);
    }

}



