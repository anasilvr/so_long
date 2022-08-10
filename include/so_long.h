/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:22:42 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/05 12:50:29 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // read, write, close
# include <fcntl.h> //open
# include <stdio.h> // perror
# include <string.h> // strerror
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/GNL/get_next_line.h"

# define ERR_MLX 1
# define ERR_ARGC "Error: Program call must be followed by ONE mapfile (.ber).\n"
# define ERR_DIR "Do you know the difference between a text file and a directory? \
You should.\n"
# define ERR_FILE "Error: Invalid file name. Ex.: \"filename.ber\"\n"
# define ERR_OPEN "Error: Couldn't open file. Check if it exists and you have the\
 right permissions.\n"
# define ERR_CHAR "Error: Undefined (invalid) character on map.\n"
# define ERR_SIZE "Error: Map is not a rectangle. \n"
# define ERR_INTEGRITY "Error: Map must contain: at least 1 (C)ollectible, \
1 (E)xit, 1 (P)layer starting position.\n"

typedef struct s_img {
	void	*img;
	void	*addr;
	int		bpp;
	int		linelenght;
	int		width;
	int		height;
	int		endian;
	char	*path;
}	t_img;

/* Collectible1-2-3 to be used if I add timed animations */
typedef struct s_sprite {
	t_img	floor;
	t_img	wall;
	t_img	exit;
	t_img	collectible;
	// t_img	collectible1;
	// t_img	collectible2;
	// t_img	collectible3;
	// t_img	collectible_done;
	t_img	success;
}	t_sprite;

//typedef struct s_coord {
//	int	x;
//	int	y;
//}	t_coord;

/* Player sides to be used if I add moving/timed animations */
/* Is there a better way to work on anymations via mlx? */
typedef struct s_player {
	int		x;
	int		y;
	t_img	player;
	t_img	player_front1;
	// t_img	player_front2;
	// t_img	player_front3;
	// t_img	player_front4;
	// t_img	player_front5;
	t_img	player_back1;
	// t_img	player_back2;
	// t_img	player_back3;
	// t_img	player_back4;
	// t_img	player_back5;
	t_img	player_right1;
	// t_img	player_right3;
	// t_img	player_right3;
	// t_img	player_right4;
	// t_img	player_right5;
	t_img	player_left1;
	// t_img	player_left2;
	// t_img	player_left3;
	// t_img	player_left4;
	// t_img	player_left5;
	t_img	player_collect;
}	t_player;

typedef struct s_game {
	int			moves;
	int			f_collectible;
	int			f_exit;
	int			f_player;
	t_player	*player;
//	t_coord		*wall;
//	t_coord		*collect;
//	t_coord		*exit;
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			width;
	int			height;
}	t_game;

/* UTILS */
void	errmsg(char *msg, int tofree, t_game *game);
void	nullify_structs(t_game *game);
char	**map_to_table(char *mapfile, t_game *game);
int		count_lines(char *mapfile, t_game *game);

/* MAP VALIDATION */
void	validate_file(int argc, char *mapfile, t_game *game);
void	parsing_map(char *mapfile, t_game *game);
void	check_mapsize(t_game *game);
void	check_mapintegrity(t_game *game);
void	validate_chars(t_game *game, char c);

/* RENDERING */


/* MLX CONTROL */

#endif