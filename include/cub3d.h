/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:50:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/09/12 09:26:54 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "macro.h"

# define RED "\033[38;5;1m"
# define RESET "\x1b[0m"

typedef struct s_image
{
	char			*path;
	char			*addr;
	void			*image;
	int				width;
	int				height;
	int				check;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
}			t_image;

typedef struct s_wall
{
	double			distance_x;
	double			distance_y;
	int				wall_side;
}				t_wall;

typedef struct s_render
{
	void			*image;
	char			*buffer;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	int				x;
	int				draw_start;
	int				draw_end;
	double			h_wall;
	double			delta_x;
	double			delta_y;
	double			ray_dir;
	double			ray_dir_x;
	double			ray_dir_y;
	int				tex_x;
	int				tex_y;
	double			tex_pos;
	double			step;
	double			step_x;
	double			step_y;
	double			side_x;
	double			side_y;
	double			perp_wall_dist;
	double			plane_x;
	double			plane_y;
	t_image			*actual_texture;
}			t_render;

typedef struct s_keys
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				left;
	int				right;
}	t_keys;

typedef struct s_map
{
	char			**full_file;
	char			**maze;
	char			*file_name;
	int				width;
	int				height;
	int				lines;
	int				columns;
	int				wall_missing;
	int				start_count;
	int				begin_maze;
}				t_map;

typedef struct s_player
{
	int				x_start_p;
	int				y_start_p;
	int				has_turn;
	double			pos_x;
	double			pos_y;
	char			direction;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}			t_player;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				color;
}			t_color;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				is_find;
	t_color			ceiling;
	t_color			ground;
	t_player		player;
	t_image			image;
	t_map			map;
	t_keys			key;
	t_render		render;
	t_image			north;
	t_image			south;
	t_image			east;
	t_image			weast;
	t_wall			wall;
}			t_data;

// =============================
// FUNCTIONS
// =============================

// Parser

int		ft_args_not_valid(int ac, char **av);
int		secure_rgb(long rgb);
int		check_double_rgb(t_data *data, char *e);

// Init data

int		ft_init_game(t_data *data);
int		ft_init_data(t_data *data);
int		init_full_file(t_data *data);
int		get_lines_columns(t_data *data);
int		check_walls(t_data *data);
char	*get_direction(t_data *data, char *dir);
int		init_rgb(t_data *data);
int		init_render(t_data *data);

// Math

int		render(t_data *data);
int		refresh_map(t_data *data);
void	put_texture_pixel(t_data *data, int x);
void	cast_ray(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
int		get_pixel(t_image *dir, int x, int y);
void	get_textures(t_data *data, t_render *render);

// Events

int		close_esc(int keycode, t_data *data);
int		close_window(t_data *data);
int		handle_keypress(int keycode, void *param);
void	ft_init_hooks(t_data *data);
int		init_maze(t_data *data);
int		is_valid_maze(t_data *data);
int		is_invalid_line(t_data *data, int i);
int		init_maze_content(t_data *data, int after_args);

// Move player

void	rotate_player(t_data *data);
void	move_player(t_data *data, double x, double y);
void	move_forward_backward(t_data *data);
void	move_left_right(t_data *data);

// Error

void	ft_display_error(char *error_msg);
void	ft_display_perror(void);
int		ft_mlx_error(void);

// Free

void	free_all(t_data *data);
void	free_map(char **map);

// Utils

void	fill_null(char **array, int len);
int		is_whitespace(char c);
int		str_iswhitespaces(char *s);
char	**ft_split_rgb(t_data *data, char *e);
int		is_tabs(char **str);
int		skip_spaces(char *str);
int		open_fd(char *file, int *fd);
int		is_arg(char *str);
int		is_space_or_nl(char c);
int		load_image(t_data *data, t_image *dir);
int		create_trgb(int t, int r, int g, int b);
int		erase_cpy(char **dst, char **src);

// Debug

void	print_array(char **array);
void	print_directions(t_data *data);
void	print_rgb(t_data *data);
void	print_invalid_args(void);
void	print_player_info(t_data *data);

#endif
