/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 16:34:39 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/15 00:07:41 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42.h"

//not sure if allowed to use
# define TILESIZE 64
// stands for bits per pixel (want to be sizeof(int32_t)
// but norminette doesn't allow it)
# define PLAYER 3
# define BACKGROUND 4

typedef struct s_data {
	mlx_t			*mlx;
	mlx_image_t		*images[5];
	mlx_texture_t	*textures[5];
	char			**map;
	int				map_height;
	int				map_width;
	int				collect_amount;
	int				p_x;
	int				p_y;
	int				bg_tiles_nb;
	bool			exit_reachable;
	bool			collects_reachable;
}	t_data;

// map making
char	**make_map(int argc, char **argv);
char	*make_map_line(int fd);
char	**alloc_map(char *map_line);
char	**line_to_map(char *map_line);

//map validation
void	check_input(int argc, char **argv);
void	map_validation(t_data *data);
int		top_bottom_check(char *str);
void	is_map_walled_off_and_rectangluar(t_data *data);
int		count_and_check_valid_tiles(char **map);
void	flood_fill(t_data *data, char **map, int x, int y);

//sprites
void	draw_sprites(t_data *data);
void	load_imgs(t_data *data);
void	place_tile(t_data *data, char c, int x, int y);
void	place_background(t_data *data);

//movement
void	player_movement(mlx_key_data_t keydata, t_data *data);
void	movement_2_electric_boogaloo(mlx_key_data_t keydata, t_data *data);
bool	can_player_move(t_data *data, int x_direction, int y_direction);
void	hide_collectible(t_data *data, int y_match, int x_match);

//utils
void	error_exit(char *s);
void	find_player_pos(t_data *data);
char	**map_copy(t_data	*data);
void	free_map(char **map);
void	init_data(t_data *data);
void	end_game(t_data *data);
#endif