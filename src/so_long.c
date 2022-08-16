/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:57:29 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/16 15:27:03 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	so_long(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERR_MLX);
	game->mlx_win = mlx_new_window(game->mlx, ((game->width - 1) * 32), \
		(game->height * 32), "so_long");
	if (!game->mlx_win)
		return (ERR_MLX);
	rendering(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, keybinding, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, quit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
