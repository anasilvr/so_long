/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:59:38 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/23 11:51:56 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->p.y - 1][game->p.x] == 'E')
	{
		if (game->f_collectible == 0)
			quit_game(game);
	}
	else if (ft_strchr("C0P", \
		game->map[game->p.y - 1][game->p.x]) != 0)
	{
		if (game->map[game->p.y - 1][game->p.x] == 'C')
			game->f_collectible -= 1;
		game->map[game->p.y][game->p.x] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.floor.img, game->p.x * 32, ((game->p.y--) * 32));
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.p_back.img, game->p.x * 32, game->p.y * 32);
		game->moves += 1;
		ft_printf("Moves = %d\n", game->moves);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->p.y + 1][game->p.x] == 'E')
	{
		if (game->f_collectible == 0)
			quit_game(game);
	}
	else if (ft_strchr("C0P", \
		game->map[game->p.y + 1][game->p.x]) != 0)
	{
		if (game->map[game->p.y + 1][game->p.x] == 'C')
				game->f_collectible -= 1;
		game->map[game->p.y][game->p.x] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.floor.img, game->p.x * 32, ((game->p.y++) * 32));
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.p_front.img, game->p.x * 32, game->p.y * 32);
		game->moves += 1;
		ft_printf("Moves = %d\n", game->moves);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->p.y][game->p.x + 1] == 'E')
	{
		if (game->f_collectible == 0)
			quit_game(game);
	}
	else if (ft_strchr("C0P", \
		game->map[game->p.y][game->p.x + 1]) != 0)
	{
		if (game->map[game->p.y][game->p.x + 1] == 'C')
				game->f_collectible -= 1;
		game->map[game->p.y][game->p.x] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.floor.img, (game->p.x++) * 32, (game->p.y * 32));
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.p_right.img, game->p.x * 32, game->p.y * 32);
		game->moves += 1;
		ft_printf("Moves = %d\n", game->moves);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->p.y][game->p.x - 1] == 'E')
	{
		if (game->f_collectible == 0)
			quit_game(game);
	}
	else if (ft_strchr("C0P", \
		game->map[game->p.y][game->p.x - 1]) != 0)
	{
		if (game->map[game->p.y][game->p.x - 1] == 'C')
				game->f_collectible -= 1;
		game->map[game->p.y][game->p.x] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.floor.img, (game->p.x--) * 32, (game->p.y * 32));
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.p_left.img, game->p.x * 32, game->p.y * 32);
		game->moves += 1;
		ft_printf("Moves = %d\n", game->moves);
	}
}
