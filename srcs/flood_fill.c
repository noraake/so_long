/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:15:22 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/05 11:33:45 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(t_flood *data, int x, int y)
{
	if (data->map[y][x] == '1' || data->map[y][x] == 'F')
		return ;
	if (data->map[y][x] == 'E')
		data->found_exit = 1;
	if (data->map[y][x] == 'C')
		data->collectibles--;
	data->map[y][x] = 'F';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

int	check_path(t_game *game)
{
	t_flood	f;
	char	**map_copy;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	f.map = map_copy;
	f.collectibles = game->collectibles;
	f.found_exit = 0;
	flood_fill(&f, game->player_x, game->player_y);
	free_map_copy(map_copy, game->map_height);
	return (f.collectibles == 0 && f.found_exit == 1);
}

char	**copy_map(t_game *game)
{
	int		y;
	char	**map_copy;

	map_copy = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (NULL);
	y = 0;
	while (y < game->map_height)
	{
		map_copy[y] = ft_strdup(game->map_grid[y]);
		if (!map_copy[y])
		{
			free_map_copy(map_copy, y);
			return (NULL);
		}
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		if (map_copy[i])
			free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
