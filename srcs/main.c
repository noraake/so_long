/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:42:30 by noakebli          #+#    #+#             */
/*   Updated: 2025/04/09 13:28:38 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long map_file.ber\n", 2);
		return (1);
	}
	if (!parse_map(argv[1], &game))
	{
		free_map(&game);
		return (1);
	}
	if (!init_game(&game))
	{
		free_map(&game);
		return (1);
	}
	return (0);
}
