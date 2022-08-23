/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:22:42 by anarodri          #+#    #+#             */
/*   Updated: 2022/08/23 11:51:06 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../libft/GNL/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

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

typedef struct s_sprite {
	t_img	floor;
	t_img	tl;
	t_img	top;
	t_img	tr;
	t_img	left;
	t_img	right;
	t_img	bl;
	t_img	bot;
	t_img	br;
	t_img	obst;
	t_img	c_exit;
	t_img	o_exit;
	t_img	baby;
	t_img	p_front;
	t_img	p_back;
	t_img	p_left;
	t_img	p_right;
}	t_sprite;

typedef struct s_player {
	int		x;
	int		y;
}	t_player;

typedef struct s_game {
	char		**map;
	int			moves;
	int			f_collectible;
	int			f_exit;
	int			e_x;
	int			e_y;
	int			f_player;
	t_player	p;
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_sprite	xpm;
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
void	rendering(t_game *game);
void	load_imgs1(t_game *game);
void	load_imgs2(t_game *game);
void	render_map(t_game *game);
void	render_walls(t_game *game, int x, int y);
void	render_obstacles(t_game *game, int x, int y);
void	render_objects(t_game *game, int x, int y);

/* GAME START AND CONTROL */

int		so_long(t_game *game);
int		gameplay(t_game *game);
int		keybinding(int key, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	end_check(t_game *game);
int		quit_game(t_game *game);
void	destroy_graphics(t_game *game);
#endif