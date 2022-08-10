/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:00:19 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/05 12:47:46 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	errmsg(char *msg, int tofree, t_game *game)
{
	if (tofree == 1)
		free_table(game->map);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	nullify_structs(t_game *game)
{
	game->moves = 0;
	game->f_collectible = 0;
	game->f_exit = 0;
	game->f_player = 0;
	game->player = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
}

char	**map_to_table(char *mapfile, t_game *game)
{
	int		i;
	int		fd;
	char	*line;
	char	**mapdata;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	mapdata = malloc(sizeof(char *) * count_lines(mapfile, game) + 1);
	if (!mapdata)
		return (NULL);
	mapdata[count_lines(mapfile, game)] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		mapdata[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	mapdata[i - 1] = ft_strjoin_free(mapdata[i - 1], "\n");
	game->height = i;
	close(fd);
	return (mapdata);
}

int	count_lines(char *mapfile, t_game *game)
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
		errmsg("Error: Empty file.\n", 0, game);
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
