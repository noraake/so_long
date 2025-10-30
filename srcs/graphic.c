/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:40:29 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/05 13:40:29 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	if (!game->textures.wall || !game->textures.player
		|| !game->textures.collectible || !game->textures.exit)
	{
		error_message("Error\nFailed to load textures", game);
		exit(1);
	}
	return (1);
}

void	put_tile_to_window(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map_grid[y][x];
			put_tile_to_window(game, x, y, tile);
			x++;
		}
		y++;
	}
}
