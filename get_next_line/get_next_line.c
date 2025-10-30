/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:16:31 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/06 17:35:55 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *save_data)
{
	char	*buffer;
	int		read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0 && !ft_strchr(save_data, '\n'))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (free(buffer), free(save_data), NULL);
		buffer[read_byte] = '\0';
		save_data = ft_strjoine(save_data, buffer);
	}
	free(buffer);
	return (save_data);
}

static char	*extract_line(char *extract_data)
{
	char	*line;
	int		i;

	if (!extract_data[0])
		return (NULL);
	i = 0;
	while (extract_data[i] && extract_data[i] != '\n')
		i++;
	if (extract_data[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (extract_data[i] && extract_data[i] != '\n')
	{
		line[i] = extract_data[i];
		i++;
	}
	if (extract_data[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*chyata(char *extract_data)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	while (extract_data[i] && extract_data[i] != '\n')
		i++;
	if (!extract_data[i])
	{
		free(extract_data);
		return (NULL);
	}
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(extract_data) - i + 1));
	if (!newstr)
		return (NULL);
	i++;
	j = 0;
	while (extract_data[i])
		newstr[j++] = extract_data[i++];
	newstr[j] = '\0';
	free(extract_data);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*stored_data = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stored_data)
		{
			free(stored_data);
		}
		return (NULL);
	}
	stored_data = read_file(fd, stored_data);
	if (!stored_data)
		return (NULL);
	line = extract_line(stored_data);
	stored_data = chyata(stored_data);
	return (line);
}
