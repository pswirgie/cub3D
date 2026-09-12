/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:04:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/09/12 09:18:10 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->render.buffer + (x * data->render.line_bytes
			+ y * (data->render.pixel_bits / 8));
	*(unsigned int *)dst = color;
}

/*
* - h_wall: height of the line to draw on screen
* - draw_start / draw_end:
*  lowest and highest pixel in which the wall is visible
*/
static void	get_wall_start_end(t_render *render)
{
	double	distance;

	distance = render->perp_wall_dist;
	render->h_wall = (HEIGHT_WINDOW / distance);
	render->draw_start = -render->h_wall / 2 + HEIGHT_WINDOW / 2;
	if (render->draw_start < 0)
		render->draw_start = 0;
	render->draw_end = render->h_wall / 2 + HEIGHT_WINDOW / 2;
	if (render->draw_end >= HEIGHT_WINDOW)
		render->draw_end = HEIGHT_WINDOW - 1;
}

static void	render_wall(t_data *data, t_render *render, int *y)
{
	int	color;

	while (*y <= render->draw_end)
	{
		render->tex_y = (int)render->tex_pos;
		if (render->tex_y < 0)
			render->tex_y = 0;
		if (render->tex_y >= render->actual_texture->height)
			render->tex_y = render->actual_texture->height - 1;
		render->tex_pos += render->step;
		color = get_pixel(render->actual_texture, render->tex_x, render->tex_y);
		put_pixel(data, *y, render->x, color);
		*y += 1;
	}
}

/*
* 1. get_wall_start_end()
*	lowest and highest pixel in which the wall is visible
* 2. get_textures()
*	choose texture et his parameters
* 3. render ceiling
* 4. render wall
* 5. render ground
*/
void	put_texture_pixel(t_data *data, int x)
{
	t_render	*render;
	int			y;

	y = 0;
	render = &data->render;
	get_wall_start_end(render);
	get_textures(data, render);
	while (y < render->draw_start)
	{
		put_pixel(data, y, x, data->ceiling.color);
		y++;
	}
	render_wall(data, render, &y);
	while (y < HEIGHT_WINDOW)
	{
		put_pixel(data, y, x, data->ground.color);
		y++;
	}
}
