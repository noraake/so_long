/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:04:11 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/05 12:19:38 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			map_width;
	int			map_height;
	char		**map_grid;
	int			player_x;
	int			player_y;
	int			player_count;
	int			collectibles;
	int			exit_count;
	int			moves;
	int			collectibles_collected;
	int			e_x;
	int			e_y;
	t_textures	textures;
}	t_game;

typedef struct s_flood_info
{
	char	**map;
	int		collectibles;
	int		found_exit;
}	t_flood;

int		parse_map(const char *filename, t_game *game);
int		init_game(t_game *game);
void	render_map(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		close_game(t_game *game);
int		load_textures(t_game *game);
void	error_message(char *message, t_game *game);
int		process_line(char *line, t_game *game);
int		validate_map(t_game *game);
int		check_path(t_game *game);
void	clean_game(t_game *game);
char	**copy_map(t_game *game);
void	free_map_copy(char **map_copy, int height);
int		add_line_to_map(char *line, t_game *game);
int		check_walls(t_game *game);
void	free_map(t_game *game);
void	clean_gnl(void);

#endif
