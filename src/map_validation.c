/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:39:09 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/04 15:50:00 by anarodri         ###   ########.fr       */
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
		errmsg(ERR_ARGC);
	if (ft_strncmp(".ber", &mapfile[ft_strlen(mapfile) - 4], \
		ft_strlen(mapfile)) != 0)
		errmsg(ERR_FILE);
	fd = open(mapfile, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		errmsg(ERR_DIR);
	}
	fd = open(mapfile, O_RDONLY, 0777);
	if (fd < 0)
		errmsg(ERR_OPEN);
	close(fd);
}

int	parsing_map(char *mapfile, t_game *game)
{
	int		fd;
	int		linelenght;
	char	**mapdata;

	mapdata = map_to_table(mapfile);
	int i = 0;
	while (mapdata[i])
	{
		printf("%s", mapdata[i]);
		i++;
	}
//	linelenght = validate_mapsize(mapdata);
	printf("[TESTTESTESTAGAIN]");
	free_table(mapdata);
//	check_mapintegrity(mapdata);
//	map_to_struct(mapdata, game);
//	free_table(mapdata); /*ERROR: NOT ALLOCATED TO BE FREED?*/
	return (0);
}

int	count_lines(char *mapfile)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		close(fd);
		errmsg("Error: Empty file.\n");
	}
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**map_to_table(char *mapfile)
{
	int		i;
	int		fd;
	char	*line;
	char	**mapdata;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	mapdata = malloc(sizeof(char *) * count_lines(mapfile) + 1);
	if (!mapdata)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		mapdata[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	mapdata[i - 1] = ft_strjoin_free(mapdata[i - 1], "\n");
	mapdata[i] = NULL;
	close(fd);
	return (mapdata);
}

int	validate_mapsize(char **mapdata, int height)
{
	int	i;
	int	width;

	i = 0;
	printf("[line = %s]\n", mapdata[i]);
	width = ft_strlen(mapdata[i]);
	printf("---> height: %d\n", height);
	printf("---> width: %d\n", width);
	while (i < height)
	{
		if (ft_strlen(mapdata[i]) != width)
			errmsg(ERR_SIZE);
		i++;
	}
	return (width);
}
/*
void	check_mapintegrity(char **mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < game->height)
	{
		j = 0;
		while (j++ < game->width)
		{
			if (i == 0 || j == 0 || \
				i == (game->height - 1) || j == (game->width - 1))
				if (game->map[i][j] != '1')
					errmsg(ERR_INTEGRITY);
			if (game->map[i][j] != 0)
				validate_chars(game, game->map[i][j], i, j);
		}
	}
	if (game->f_collectible == 0 || game->f_exit == 0 || \
		game->f_player == 0)
		errmsg(ERR_INTEGRITY);
}

 Should I check/stop the program if I had multiple exits?
void	validate_chars(t_game *game, char c, int x, int y)
{
	if (c != '1' && c != 'C' && c != 'E' && c != 'P')
		errmsg(ERR_CHAR);
	else if (c == 'C')
	{
		game->f_collectible += 1;
		game->collect->x = x;
		game->collect->y = y;
	}
	else if (c == 'E')
	{
		game->f_exit += 1;
		game->exit->x = x;
		game->exit->y = y;
	}
	else if (c == 'P')
	{
		if (game->f_player == 1)
			errmsg("Error: Too many players. Máx.: 1\n");
		else
		{
			game->f_player = 1;
			game->player->x = x;
			game->player->y = y;
		}
	}
}
*/