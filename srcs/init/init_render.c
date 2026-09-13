/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:01:54 by pswirgie          #+#    #+#             */
/*   Updated: 2026/09/13 11:21:14 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"

static void	start_east_weast(t_data *data)
{
	if (data->player.direction == 'E')
	{
		data->player.dir_y = 1;
		data->player.dir_x = 0;
		data->render.plane_x = CAM_PLANE;
		data->render.plane_y = 0;
	}
	else if (data->player.direction == 'W')
	{
		data->player.dir_y = -1;
		data->player.dir_x = 0;
		data->render.plane_x = -CAM_PLANE;
		data->render.plane_y = 0;
	}
}

static void	start_north_south(t_data *data)
{
	if (data->player.direction == 'N')
	{
		data->player.dir_y = 0;
		data->player.dir_x = -1;
		data->render.plane_x = 0;
		data->render.plane_y = CAM_PLANE;
	}
	else if (data->player.direction == 'S')
	{
		data->player.dir_y = 0;
		data->player.dir_x = 1;
		data->render.plane_x = 0;
		data->render.plane_y = -CAM_PLANE;
	}
}

/*
* create a buffer image in order to write in -> image render
*/
int	init_render(t_data *data)
{
	data->render.image = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->render.image)
		return (1);
	data->render.buffer = mlx_get_data_addr(data->render.image,
			&data->render.pixel_bits, &data->render.line_bytes,
			&data->render.endian);
	if (!data->render.buffer)
		return (1);
	start_north_south(data);
	start_east_weast(data);
	if (render(data))
		return (1);
	return (0);
}
