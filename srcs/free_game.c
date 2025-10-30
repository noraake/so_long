/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:09:53 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/09 13:39:36 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	if (game && game->map_grid)
	{
		while (y < game->map_height)
		{
			if (game->map_grid[y])
			{
				free(game->map_grid[y]);
				game->map_grid[y] = NULL;
			}
			y++;
		}
		free(game->map_grid);
		game->map_grid = NULL;
	}
}

void	clean_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		if (game->textures.wall)
			(1) && (mlx_destroy_image(game->mlx, game->textures.wall),
				game->textures.wall = NULL);
		if (game->textures.player)
			(1) && (mlx_destroy_image(game->mlx, game->textures.player),
				game->textures.player = NULL);
		if (game->textures.collectible)
			(1) && (mlx_destroy_image(game->mlx, game->textures.collectible),
				game->textures.collectible = NULL);
		if (game->textures.exit)
			(1) && (mlx_destroy_image(game->mlx, game->textures.exit),
				game->textures.exit = NULL);
		if (game->win)
			(1) && (mlx_destroy_window(game->mlx, game->win), game->win = NULL);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

int	close_game(t_game *game)
{
	clean_game(game);
	free_map(game);
	clean_gnl();
	exit(0);
	return (0);
}

void	clean_gnl(void)
{
	get_next_line(-1);
}

void	error_message(char *message, t_game *game)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free_map(game);
	clean_game(game);
	exit(EXIT_FAILURE);
}
