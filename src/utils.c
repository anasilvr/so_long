/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:00:19 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/03 10:55:47 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	nullify_structs(t_game *game)
{
	game->moves = 0;
	game->f_collectible = 0;
	game->f_exit = 0;
	game->f_player = 0;
	game->player = NULL;
	game->wall = NULL;
	game->collect = NULL;
	game->exit = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
}

void	errmsg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
			free(map[i]);
		free(map);
	}
}
