/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:56:45 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/09 13:30:54 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	process_line(char *line, t_game *game)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line[line_length - 1] == '\n')
	{
		line[line_length - 1] = '\0';
		line_length--;
	}
	if (game->map_width == 0)
		game->map_width = line_length;
	else if (line_length != game->map_width)
	{
		get_next_line(-1);
		free(line);
		error_message("Error\nLa carte n'est pas rectangulaire", game);
	}
	if (!add_line_to_map(line, game))
	{
		return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (game->map_width < 3 || game->map_height < 3)
		error_message("Error\nLa carte est trop petite", game);
	if (game->player_count != 1)
		error_message("Error\nLa carte doit avoir une position", game);
	if (game->collectibles < 1)
		error_message("Error\nLa carte doit avoir un collectible", game);
	if (game->exit_count != 1)
		error_message("Error\nLa carte doit avoir au moins une sortie", game);
	if (!check_walls(game))
		error_message("Error\nLa carte doit être entourée de murs", game);
	if (!check_path(game))
		error_message("Error\nPas de chemin valide", game);
	return (1);
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!game || !game->map_grid || game->map_width <= 0
		|| game->map_height <= 0)
		return (0);
	while (++x < game->map_width)
	{
		if (game->map_grid[0][x] != '1' || game->map_grid[game->map_height
			- 1][x] != '1')
			return (0);
	}
	while (++y < game->map_height)
	{
		if (game->map_grid[y][0] != '1' || game->map_grid[y][game->map_width
			- 1] != '1')
			return (0);
	}
	return (1);
}
