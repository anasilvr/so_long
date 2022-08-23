/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:01:54 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/23 11:39:41 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	gameplay(t_game *game)
{
	if (game->f_collectible == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.o_exit.img, (game->e_x * 32), (game->e_y * 32));
	}
	mlx_hook(game->mlx_win, 2, 1L << 0, &keybinding, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, &quit_game, game);
	return (0);
}

void	end_check(t_game *game)
{
	if (game->f_collectible == 0)
		ft_printf("Ohnomnomnom... GG! All babies were fed. ♥\
			 (Total moves: %d)\n", game->moves);
	else
		ft_printf("Oh no! Missing babies will be hangry!\
			 (Total moves: %d)\n", game->moves);
}
