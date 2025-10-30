/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:06:36 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/08 23:53:18 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game(t_game *game, char *line, int i)
{
	if (line[i] == 'P')
	{
		game->player_x = i;
		game->player_y = game->map_height;
		game->player_count++;
	}
	else if (line[i] == 'C')
		game->collectibles++;
	else if (line[i] == 'E')
	{
		game->exit_count++;
		game->e_x = i;
		game->e_y = game->map_height;
	}
	else if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
		&& line[i] != 'C' && line[i] != 'E')
	{
		if (game->map_grid && game->map_height >= 0
			&& game->map_grid[game->map_height])
		{
			free(game->map_grid[game->map_height]);
			game->map_grid[game->map_height] = NULL;
		}
		error_message("Caractère invalide dans la carte", game);
	}
}

int	resize_map_grid(t_game *game)
{
	char	**new_grid;

	if (game->map_height == 0)
		new_grid = (char **)malloc(sizeof(char *));
	else
		new_grid = (char **)realloc(game->map_grid, (game->map_height + 1)
				* sizeof(char *));
	if (!new_grid)
	{
		free_map(game);
		return (0);
	}
	game->map_grid = new_grid;
	return (1);
}

int	add_line_to_map(char *line, t_game *game)
{
	int	i;

	if (!resize_map_grid(game))
		return (0);
	game->map_grid[game->map_height] = ft_strdup(line);
	if (!game->map_grid[game->map_height])
		error_message("Erreur d'allocation de mémoire", game);
	i = 0;
	while (line[i])
	{
		ft_game(game, line, i);
		i++;
	}
	game->map_height++;
	return (1);
}
