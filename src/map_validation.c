/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:39:09 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/10 15:48:02 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A map is: a description file ending with the .ber
It has to be constructed with 3 components:
	-> walls, collectibles, and free space.

The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position

The map MUST:
• contain at least 1 exit, 1 collectible, and 1 starting position.
• be rectangular.
• be closed/surrounded by walls.

	Any misconfiguration: return("Error: explicit error message\n");
*/

#include "../include/so_long.h"

void	validate_file(int argc, char *mapfile, t_game *game)
{
	int	fd;

	if (argc != 2)
		errmsg(ERR_ARGC, 0, game);
	if (ft_strncmp(".ber", &mapfile[ft_strlen(mapfile) - 4], \
		ft_strlen(mapfile)) != 0)
		errmsg(ERR_FILE, 0, game);
	fd = open(mapfile, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		errmsg(ERR_DIR, 0, game);
	}
	fd = open(mapfile, O_RDONLY, 0777);
	if (fd < 0)
		errmsg(ERR_OPEN, 0, game);
	close(fd);
}

void	parsing_map(char *mapfile, t_game *game)
{
	game->map = map_to_table(mapfile, game);
	check_mapsize(game);
	check_mapintegrity(game);
}

void	check_mapsize(t_game *game)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != width)
			errmsg(ERR_SIZE, 1, game);
		i++;
	}
	game->width = width;
}

void	check_mapintegrity(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width - 1)
		{
			if (x == 0 || y == 0 || y == (game->height - 1) || \
				x == (game->width - 2))
			{
				if (game->map[y][x] != '1')
					errmsg("Error: Map not surrounded by walls.\n", 1, game);
			}
			if (game->map[y][x] != '0')
				validate_chars(game, game->map[y][x]);
		}
	}
	if (game->f_collectible == 0 || game->f_exit == 0 || \
		game->f_player == 0)
		errmsg(ERR_INTEGRITY, 1, game);
}

void	validate_chars(t_game *game, char c)
{
	if (c != '1' && c != 'C' && c != 'E' && c != 'P')
		errmsg(ERR_CHAR, 1, game);
	else if (c == 'C')
		game->f_collectible += 1;
	else if (c == 'E')
		game->f_exit += 1;
	else if (c == 'P')
	{
		if (game->f_player == 1)
			errmsg("Error: Too many players. Máx.: 1.\n", 1, game);
		else
			game->f_player = 1;
	}
}
