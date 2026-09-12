/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:59:10 by pswirgie          #+#    #+#             */
/*   Updated: 2026/09/12 08:46:57 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>

int	get_pixel(t_image *dir, int x, int y)
{
	char	*pixel;

	pixel = dir->addr + (y * dir->line_bytes + x * (dir->pixel_bits / 8));
	return (*(unsigned int *)pixel);
}

static void	init_dda_direction_y(t_data *data)
{
	t_render	*render;
	int			player_y;

	render = &data->render;
	player_y = (int)data->player.pos_x;
	if (render->ray_dir_y == 0)
		render->delta_y = 1e30;
	else
		render->delta_y = fabs(1.0 / render->ray_dir_y);
	if (render->ray_dir_y < 0)
	{
		render->step_y = -1;
		render->side_y = (data->player.pos_x - player_y) * (render->delta_y);
	}
	else
	{
		render->step_y = 1;
		render->side_y = (player_y + 1.0 - data->player.pos_x)
			* (render->delta_y);
	}
}

static void	init_dda_direction_x(t_data *data)
{
	t_render	*render;
	int			player_x;

	render = &data->render;
	player_x = (int) data->player.pos_y;
	if (render->ray_dir_x == 0)
		render->delta_x = 1e30;
	else
		render->delta_x = fabs(1.0 / render->ray_dir_x);
	if (render->ray_dir_x < 0)
	{
		render->step_x = -1;
		render->side_x = (data->player.pos_y - player_x) * (render->delta_x);
	}
	else
	{
		render->step_x = 1;
		render->side_x = (player_x + 1.0 - data->player.pos_y)
			* (render->delta_x);
	}
}

static void	dda_loop(t_data *data, t_render *render, int *side)
{
	int			x;
	int			y;

	*side = 0;
	x = (int) data->player.pos_y;
	y = (int) data->player.pos_x;
	while (x < data->map.lines && y < data->map.columns
		&& data->map.maze[x]
		&& data->map.maze[x][y]
		&& data->map.maze[x][y] != '1')
	{
		if (render->side_x < render->side_y)
		{
			render->side_x += render->delta_x;
			x += render->step_x;
			*side = 0;
		}
		else
		{
			render->side_y += render->delta_y;
			y += render->step_y;
			*side = 1;
		}
	}
}

/*
* - The ray is composed of two sub-rays: 1 horizontal and 1 vertical,
* whose direction is based on the player's direction, combined with
* the direction given by a camera plane, so that each ray corresponds
* to a column of the window of size WIDTH_WINDOW.
* - The ray advances step by step until it hits a wall.
* - This distance gives us the information needed to render the walls
* (the greater the distance, the smaller the wall appears on screen).
* - The positions of the horizontal and vertical ray hits tell us
* whether we hit a horizontal side or a vertical side of the wall.
* - To determine the wall's orientation (north, south, east, west),
* we use the player's direction as a reference.
* For example, if the player is looking east, they are seeing
* the west face of the wall.
*/
void	cast_ray(t_data *data)
{
	t_render	*render;
	double		camera_x;
	int			side;

	render = &data->render;
	camera_x = 2 * render->x / (double)WIDTH_WINDOW - 1;
	render->ray_dir_x = data->player.dir_x + render->plane_x * camera_x;
	render->ray_dir_y = data->player.dir_y + render->plane_y * camera_x;
	init_dda_direction_x(data);
	init_dda_direction_y(data);
	dda_loop(data, render, &side);
	if (side == 0)
		data->render.perp_wall_dist = render->side_x - render->delta_x;
	else
		data->render.perp_wall_dist = render->side_y - render->delta_y;
	data->wall.wall_side = side;
	data->wall.distance_x = data->player.pos_y + render->perp_wall_dist
		* render->ray_dir_x;
	data->wall.distance_y = data->player.pos_x + render->perp_wall_dist
		* render->ray_dir_y;
	if (render->perp_wall_dist <= 0.0001)
		render->perp_wall_dist = 0.0001;
}
