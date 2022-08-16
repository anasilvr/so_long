/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:43:06 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/16 15:07:28 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	rendering(t_game *game)
{
	load_imgs1(game);
	load_imgs2(game);
	render_map(game);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width - 1)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->xpm.floor.img, (x * 32), (y * 32));
			if (game->map[y][x] == '1')
			{
				if ((x > 0 && x < game->width - 2) && \
					(y > 0 && y < game->height - 2))
					render_obstacles(game, x, y);
				else
					render_walls(game, x, y);
			}
			else
				render_objects(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_walls(t_game *game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.tl.img, (x * 32), (y * 32));
	if ((x > 0 && x < game->width - 1) && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.top.img, (x * 32), (y * 32));
	if (x == game->width - 2 && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.tr.img, (x * 32), (y * 32));
	if (x == 0 && (y > 0 && y < game->height - 1))
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.left.img, (x * 32), (y * 32));
	if (x == game->width - 2 && (y > 0 && y < game->height - 1))
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.right.img, (x * 32), (y * 32));
	if (x == 0 && y == game->height - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.bl.img, (x * 32), (y * 32));
	if ((x > 0 && x < game->width - 1) && y == game->height - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.bot.img, (x * 32), (y * 32));
	if (x == game->width - 2 && y == game->height - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.br.img, (x * 32), (y * 32));
}

void	render_obstacles(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.obst.img, (x * 32), (y * 32));
}

void	render_objects(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.baby.img, (x * 32), (y * 32));
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.c_exit.img, (x * 32), (y * 32));
	if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->xpm.mom.img, (x * 32), (y * 32));
		game->player.x = x;
		game->player.y = y;
	}
}

