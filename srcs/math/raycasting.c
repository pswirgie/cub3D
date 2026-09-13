/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/09/13 12:55:02 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <stdint.h>
#include <math.h>
#include "../../lib/libft/libft.h"

int	render(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH_WINDOW)
	{
		data->render.x = x;
		cast_ray(data);
		put_texture_pixel(data, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->render.image, 0, 0);
	return (0);
}

/*
* move and rotate here combined with keyrelease allow continuous
* movement and rotation while a key is held down
*/
int	refresh_map(t_data *data)
{
	rotate_player(data);
	move_forward_backward(data);
	move_left_right(data);
	render(data);
	return (0);
}
