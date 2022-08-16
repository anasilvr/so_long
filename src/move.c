/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:59:38 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/16 16:46:54 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] == 'E')
	{
		if (game->f_collectible == 0)
			printf("Total moves: %d\nGG!",game->moves); // Exit game with success message and total moves
	}
	else if (ft_strchr("C0P", game->map[game->player.y - 1][game->player.x]) != 0)
	{
		if (game->map[game->player.y - 1][game->player.x] == 'C')
			game->f_collectible -= 1;
		game->map[game->player.y][game->player.x] = '0';
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.floor.img, game->player.x * 32, (game->player.y-- * 32));
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.mom.img, game->player.x * 32, game->player.y * 32);
		game->moves += 1;
		printf("Moves = %d\n", game->moves);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] == 'E')
	{
		if (game->f_collectible == 0)
			printf("Total moves: %d\nGG!",game->moves); // Exit game with success message and total moves
	}
	else if (ft_strchr("C0P", game->map[game->player.y + 1][game->player.x]) != 0)
	{
		if (game->map[game->player.y + 1][game->player.x] == 'C')
				game->f_collectible -= 1;
		game->map[game->player.y][game->player.x] = '0';
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.floor.img, game->player.x * 32, (game->player.y++ * 32));
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.mom.img, game->player.x * 32, game->player.y * 32);
		game->moves += 1;
		printf("Moves = %d\n", game->moves);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] == 'E')
	{
		if (game->f_collectible == 0)
			printf("Total moves: %d\nGG!",game->moves); // Exit game with success message and total moves
	}
	else if (ft_strchr("C0P", game->map[game->player.y][game->player.x + 1]) != 0)
	{
		if (game->map[game->player.y][game->player.x + 1] == 'C')
				game->f_collectible -= 1;
		game->map[game->player.y][game->player.x] = '0';
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.floor.img, game->player.x++ * 32, (game->player.y * 32));
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.mom.img, game->player.x * 32, game->player.y * 32);
		game->moves += 1;
		printf("Moves = %d\n", game->moves);
	}
}

void	move_left(t_game *game)
{
		if (game->map[game->player.y][game->player.x - 1] == 'E')
	{
		if (game->f_collectible == 0)
			printf("Total moves: %d\nGG!",game->moves); // Exit game with success message and total moves
	}
	else if (ft_strchr("C0P", game->map[game->player.y][game->player.x - 1]) != 0)
	{
		if (game->map[game->player.y - 1][game->player.x] == 'C')
				game->f_collectible -= 1;
		game->map[game->player.y][game->player.x] = '0';
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.floor.img, game->player.x-- * 32, (game->player.y * 32));
		mlx_put_image_to_window(game->mlx,game->mlx_win, game->xpm.mom.img, game->player.x * 32, game->player.y * 32);
		game->moves += 1;
		printf("Moves = %d\n", game->moves);
	}
}

// create a function that checks if all collectibles were collected and changes the exit accordinly