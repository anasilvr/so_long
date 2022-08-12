/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:26:24 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/10 16:40:28 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	keybinding(int key, t_game *game)
{
	if (key == 53)
		quit_game(game);
	return (0);
}

int	quit_game(t_game *game)
{
	if(game->map)
		free_table(game->map);
	if(game->mlx)
		destroy_graphics(game);
	exit(0);
}

void	destroy_graphics(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
}