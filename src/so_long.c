/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:57:29 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/23 10:43:00 by anarodri         ###   ########.fr       */
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
	mlx_loop_hook(game->mlx, &gameplay, game);
	mlx_loop(game->mlx);
	return (0);
}
