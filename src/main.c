/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:57:16 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/16 13:44:53 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc (sizeof(t_game));
	nullify_structs(game);
	validate_file(argc, argv[1], game);
	printf("[FILE VALIDATED]\n");
	parsing_map(argv[1], game);
	printf("[MAP VALIDATED]\n");
	if (so_long(game) == 1)
		errmsg("Error: MLX fail.", 1, game);
	if (game->map)
		free_table(game->map);
	free(game);
	return (0);
}
