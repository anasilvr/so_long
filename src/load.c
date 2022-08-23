/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:35:25 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/23 11:43:15 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_imgs1(t_game *game)
{
	game->xpm.floor.img = mlx_xpm_file_to_image(game->mlx, "./sprites/mid1.xpm"\
		, &game->xpm.floor.width, &game->xpm.floor.height);
	game->xpm.tl.img = mlx_xpm_file_to_image(game->mlx, "./sprites/tl.xpm"\
		, &game->xpm.tl.width, &game->xpm.tl.height);
	game->xpm.top.img = mlx_xpm_file_to_image(game->mlx, "./sprites/top.xpm"\
		, &game->xpm.top.width, &game->xpm.top.height);
	game->xpm.tr.img = mlx_xpm_file_to_image(game->mlx, "./sprites/tr.xpm"\
		, &game->xpm.tr.width, &game->xpm.tr.height);
	game->xpm.left.img = mlx_xpm_file_to_image(game->mlx, "./sprites/left.xpm"\
		, &game->xpm.left.width, &game->xpm.left.height);
	game->xpm.right.img = mlx_xpm_file_to_image(game->mlx, "./sprites/right.xpm"\
		, &game->xpm.right.width, &game->xpm.right.height);
	game->xpm.bl.img = mlx_xpm_file_to_image(game->mlx, "./sprites/bl.xpm"\
		, &game->xpm.bl.width, &game->xpm.bl.height);
	game->xpm.bot.img = mlx_xpm_file_to_image(game->mlx, "./sprites/bottom.xpm"\
		, &game->xpm.bot.width, &game->xpm.bot.height);
	game->xpm.br.img = mlx_xpm_file_to_image(game->mlx, "./sprites/br.xpm"\
		, &game->xpm.br.width, &game->xpm.br.height);
	game->xpm.obst.img = mlx_xpm_file_to_image(game->mlx, "./sprites/obst1.xpm"\
		, &game->xpm.br.width, &game->xpm.br.height);
}

void	load_imgs2(t_game *game)
{
	game->xpm.c_exit.img = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm"\
		, &game->xpm.c_exit.width, &game->xpm.c_exit.height);
	game->xpm.o_exit.img = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/openexit1.xpm", &game->xpm.o_exit.width, \
		&game->xpm.o_exit.height);
	game->xpm.p_front.img = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/p_front.xpm", &game->xpm.p_front.width, \
		&game->xpm.p_front.height);
	game->xpm.p_back.img = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/p_back.xpm", &game->xpm.p_back.width, \
		&game->xpm.p_back.height);
	game->xpm.p_left.img = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/p_left.xpm", &game->xpm.p_left.width, \
		&game->xpm.p_left.height);
	game->xpm.p_right.img = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/p_right.xpm", &game->xpm.p_right.width, \
		&game->xpm.p_right.height);
	game->xpm.baby.img = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/baby1.xpm", &game->xpm.baby.width, &game->xpm.baby.height);
}
