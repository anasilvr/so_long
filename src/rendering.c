/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:43:06 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/12 13:50:20 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_game(t_game *game)
{
	int a;
	a = -1;

	while (game->map[++a])
	{
		printf("%s", game->map[a]);
	}
	printf("\n");
	get_mapimg(game);
	render_map(*game);
//	init_objects(game, mlx);
}

void	get_mapimg(t_game *game)
{
	game->xpm.floor.img = mlx_xpm_file_to_image(game->map, "./sprites/mid1.xpm", &game->xpm.floor.width, &game->xpm.floor.height);
	game->xpm.wall.img = mlx_xpm_file_to_image(game->map, "./sprites/wall.xpm", &game->xpm.wall.width, &game->xpm.wall.height);
	game->xpm.closed_exit.img = mlx_xpm_file_to_image(game->map, "./sprites/E/exit.xpm", &game->xpm.closed_exit.width, &game->xpm.closed_exit.height);
	game->xpm.collectible.img = mlx_xpm_file_to_image(game->map, "./sprites/C/baby1.xpm", &game->xpm.collectible.width, &game->xpm.collectible.height);
	game->xpm.player.img = mlx_xpm_file_to_image(game->map, "./sprites/P/front1.xpm", &game->xpm.player.width, &game->xpm.player.height);
}

void	render_map(t_game game)
{
	int a;
	a = -1;

	while (game.map[++a])
	{
		printf("%s", game.map[a]);
	}

	int	x;
	int	y;

	y = -1;
	while (++y < game.height)
	{
		x = -1;
		while (++x < game.width - 1)
			mlx_put_image_to_window(game.mlx, game.mlx_win, game.xpm.floor.img, (x * game.bits), (y * game.bits));
	}
	y = 0;
	while (y < game.height)
	{
		x = 0;
		while (x < game.width - 1)
		{
			if (game.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.xpm.wall.img, (x * 32), (y * 32));
			if (game.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.xpm.collectible.img, (x * 32), (y * 32));
			if (game.map[y][x] == 'E')
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.xpm.closed_exit.img, (x * 32), (y * 32));
			if (game.map[y][x] == 'P')
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.xpm.player.img, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}

void	img_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->xpm.wall.img, (x * 32), (y * 32));
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->xpm.collectible.img, (x * game->bits), (y * game->bits));
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->xpm.closed_exit.img, (x * game->bits), (y * game->bits));
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->xpm.player.img, (x * game->bits), (y * game->bits));
}