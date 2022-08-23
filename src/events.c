/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:26:24 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/23 11:24:46 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	keybinding(int key, t_game *game)
{
	if (key == 13 || key == 126)
		move_up(game);
	else if (key == 1 || key == 125)
		move_down(game);
	else if (key == 2 || key == 124)
		move_right(game);
	else if (key == 0 || key == 123)
		move_left(game);
	else if (key == 53)
		quit_game(game);
	return (0);
}

int	quit_game(t_game *game)
{
	end_check(game);
	if (game->map)
		free_table(game->map);
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

void	destroy_graphics(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
}
