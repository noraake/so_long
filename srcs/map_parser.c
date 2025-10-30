/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:45:43 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/09 13:25:03 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define EXTENTION ".ber"

int	check_file_extension(const char *filename)
{
	int	i;
	int	j;
	int	k;

	i = ft_strlen(filename) - 1;
	j = ft_strlen(EXTENTION) - 1;
	k = 0;
	while (filename[k++])
	{
		if (filename[k] == '/')
		{
			k++;
			if (filename[k] == '.')
				return (1);
		}
	}
	while (j >= 0)
	{
		if (filename[i--] != EXTENTION[j--])
			return (1);
	}
	return (0);
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_message("Error\nImpossible d'ouvrir le fichier", NULL);
	return (fd);
}

int	handle_map_line(char *line, t_game *game)
{
	if (line[0] == '\n' || line[0] == '\0')
	{
		ft_putstr_fd("Error\nLa carte contient une ligne vide\n", 2);
		return (0);
	}
	if (!process_line(line, game))
		return (0);
	return (1);
}

int	read_map_lines(int fd, t_game *game)
{
	char	*line;
	int		result;

	result = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!handle_map_line(line, game))
		{
			free(line);
			result = 0;
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	clean_gnl();
	if (!result)
		free_map(game);
	else if (game->map_height == 0)
		return (ft_putstr_fd("Error\nLa carte est vide\n", 2), 0);
	return (result);
}

int	parse_map(const char *filename, t_game *game)
{
	int	fd;

	game->map_grid = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player_count = 0;
	game->collectibles = 0;
	game->exit_count = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	if (check_file_extension(filename) != 0)
		error_message("Error\nL'extension du fichier doit être .ber", game);
	fd = open_file(filename);
	if (!read_map_lines(fd, game))
		return (0);
	close(fd);
	if (!validate_map(game))
	{
		free_map(game);
		return (0);
	}
	return (1);
}
