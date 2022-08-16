/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:35:25 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/16 14:23:41 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_imgdata(void *mlx, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image (mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr (img->img, &img->bpp, &img->linelenght, \
		&img->endian);
}

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
	game->xpm.baby.img = mlx_xpm_file_to_image(game->mlx, "./sprites/baby1.xpm"\
		, &game->xpm.baby.width, &game->xpm.baby.height);
	game->xpm.mom.img = mlx_xpm_file_to_image(game->mlx, "./sprites/front1.xpm"\
		, &game->xpm.mom.width, &game->xpm.mom.height);
//SCALE CAUSING SEGFAULT
	game->xpm.baby.img = image_scale(&game->xpm.baby, 1, game->mlx);

}

void	own_pixel_put(t_img *tmp, int x, int y, unsigned int color)
{
	char	*dst;

	dst = tmp->addr + (y * tmp->linelenght + x * (tmp->bpp / 8));
	*(unsigned int *) dst = color;
}

unsigned int	pick_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->linelenght + x * (img->bpp / 8));
	return (*(unsigned int *) dst);
}

void	*image_scale(t_img *img, float scale, void *mlx)
{
	t_img			tmp;
	int				x;
	int				y;
	unsigned int	color;

	tmp.width = img->width * scale;
	tmp.height = img->height * scale;
	tmp.img = mlx_new_image(mlx, tmp.width, tmp.height);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, \
		&tmp.linelenght, &tmp.endian);
	y = 0;
	while (y < img->height * scale)
	{
		x = 0;
		while (x < (img->width * scale))
		{
			color = pick_color(img, (x / scale), (y / scale));
			own_pixel_put(&tmp, x, y, color);
			x++;
		}
		y++;
	}
	return (tmp.img);
}
