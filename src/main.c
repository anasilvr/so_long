/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:57:16 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/03 11:53:36 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc (sizeof(t_game));
	nullify_structs(game);
	validate_file(argc, argv[1], game);
	if (parsing_map(argv[1], game) != 0)
		errmsg("Error: Parsing failed\n");
//	so_long(infosinfosinfos);
//	free(game);
	return (0);
}
