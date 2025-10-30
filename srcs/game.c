/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:24:41 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/09 00:42:40 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = game->map_width * TILE_SIZE;
	win_height = game->map_height * TILE_SIZE;
	if (!game->map_grid || !game->map_grid[0])
	{
		error_message("Error\nMap is not loaded correctly.\n", game);
		return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game);
		return (0);
	}
	game->map_width = ft_strlen(game->map_grid[0]);
	game->win = mlx_new_window(game->mlx, win_width, win_height, "So Long");
	if (!game->win || !load_textures(game))
		return (clean_game(game), 0);
	render_map(game);
	mlx_hook(game->win, 2, 1, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (1);
}

static int	check_and_handle_interaction(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height)
		return (0);
	if (game->map_grid[new_y][new_x] == '1')
		return (0);
	if (game->map_grid[new_y][new_x] == 'C')
		game->collectibles--;
	if (game->map_grid[new_y][new_x] == 'E')
	{
		if (game->collectibles == 0)
		{
			game->moves++;
			ft_printf("Move:%d\n", game->moves);
			error_message("Félicitations ! Vous avez gagné !", game);
			close_game(game);
		}
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	old_x = game->player_x;
	old_y = game->player_y;
	if (!check_and_handle_interaction(game, new_x, new_y))
		return ;
	if (old_x == game->e_x && old_y == game->e_y)
		game->map_grid[old_y][old_x] = 'E';
	else
		game->map_grid[old_y][old_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map_grid[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Move:%d\n", game->moves);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}
