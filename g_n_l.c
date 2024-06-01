/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_n_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:35:27 by iqattami          #+#    #+#             */
/*   Updated: 2024/05/31 15:41:35 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*buffer_reader(char *str, int fd)
{
	ssize_t	read_bytes;
	char	*buffer;
	char	*tmp;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = 0;
	}
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(str), NULL);
		buffer[read_bytes] = '\0';
		tmp = str;
		str = ft_strjoin1(str, buffer);
		free(tmp);
	}
	return (free(buffer), str);
}

char	*readline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*line_remover(char *str)
{
	int		i;
	int		j;
	char	*holder;

	if (!*str)
		return (free(str), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	holder = malloc(ft_strlen(str) - i + 1);
	if (!holder)
		return (free(str), NULL);
	j = 0;
	while (str[i])
	{
		holder[j] = str[i];
		i++;
		j++;
	}
	holder[j] = '\0';
	return (free(str), holder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = buffer_reader(str, fd);
	if (!str)
		return (NULL);
	line = readline(str);
	str = line_remover(str);
	if (!str)
		return (free(line), NULL);
	return (line);
}

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*sub;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (start + len > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	sub = malloc(sizeof(char) * (len + 1));
// 	i = 0;
// 	if (!sub)
// 		return (NULL);
// 	while (len > i)
// 		sub[i++] = s[start++];
// 	sub[i] = '\0';
// 	return (sub);
// }


// char	*fre(char *s)
// {
// 	if (s)
// 		free(s);
// 	return (NULL);
// }

// static char	*set_line(char *line_buffer)
// {
// 	char	*substring;
// 	ssize_t	i;

// 	i = 0;
// 	if (!line_buffer[i])
// 		return (NULL);
// 	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
// 		i++;
// 	substring = ft_substr(line_buffer, 0, i + 1);
// 	if (!substring)
// 		return (free(substring), NULL);
// 	return (substring);
// }

// char	*next_line(char *buffer)
// {
// 	int		i;
// 	int		j;
// 	char	*next_line;

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (!buffer[i])
// 		return (free(buffer), NULL);
// 	i++;
// 	next_line = malloc(ft_strlen(buffer) - i + 1);
// 	if (!next_line)
// 		return (free(buffer), NULL);
// 	j = 0;
// 	while (buffer[i])
// 		next_line[j++] = buffer[i++];
// 	next_line[j] = '\0';
// 	free(buffer);
// 	return (next_line);
// }

// char	*fill_line(int fd, char *s_output)
// {
// 	ssize_t	read_buffer;
// 	char	*buffer;

// 	read_buffer = 1;
// 	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while (read_buffer != 0 && !(ft_strchr(s_output, '\n')))
// 	{
// 		read_buffer = read(fd, buffer, BUFFER_SIZE);
// 		if (read_buffer == -1)
// 			return (fre(buffer), fre(s_output), NULL);
// 		else if (read_buffer == 0)
// 			break ;
// 		buffer[read_buffer] = '\0';
// 		if (!s_output)
// 			s_output = ft_strdup("");
// 		s_output = ft_strjoin1(s_output, buffer);
// 	}
// 	free(buffer);
// 	return (s_output);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*rest;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	rest = fill_line(fd, rest);
// 	if (!rest)
// 		return (NULL);
// 	line = set_line(rest);
// 	rest = next_line(rest);
// 	return (line);
// }
