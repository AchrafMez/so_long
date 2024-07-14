/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:03:21 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/14 01:35:26 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_print/ft_printf.h"
# include "./getnextline/get_next_line.h"
# include "/Users/amezioun/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char			**map;
	mlx_t			*mlx;
	mlx_image_t		*img[5];
	mlx_texture_t	*texture[5];
	int				width;
	int				height;
	int				x;
	int				y;
	int				exit_y;
	int				exit_x;
	int				player_y;
	int				player_x;
	int				player;
	int				coins;
	int				exit;
	int				moves;
}					t_map;

//treat
int					camp(char *filename);
void				treat(char *filename, t_map *mlx);

//loading
void				load_png(t_map *mlx);
void				png_to_image(t_map *mlx);
void				ft_put_floor(t_map *mlx);
void				ft_put_exit(t_map *mlx);
void				put_pictures(t_map *mlx);

//flood fill
void				player_check(char **map);
void				flood_fill(char **map, int y, int x);
int					check_path(char **map);

void				player_check(char **map);
void				ft_error(t_map *mlx);
int					check_path(char **map);

//rectangular
void				ones_line(t_map *mlx, int y);
int					map_len(t_map *mlx);
int					map_rectangular(t_map *mlx);

//map_check
void				init(t_map *mlx);
void				map_check_helper(t_map *mlx);
int					map_check(t_map *mlx);
int					check(char *line);

//ft_store
void				empty_map(void);
void				ft_store(char *filename, t_map *mlx);
int					map_lines(int fd, char *filename);

//movements
void				get_e(t_map *mlx);
void				move_up(t_map *mlx);
void				move_down(t_map *mlx);
void				move_right(t_map *mlx);
void				move_left(t_map *mlx);

//keys
void				key_press(struct mlx_key_data key_data, void *param);

//exit
void				ft_camp_error(void);
void				delete_texture(t_map *mlx);
void				ft_error_free(t_map *mlx);
void				ft_error(t_map *mlx);
void				ft_free(char **map, int i);
#endif