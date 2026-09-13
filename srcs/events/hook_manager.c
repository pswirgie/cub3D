/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:14:22 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/09/13 10:19:21 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"

/*
* move here and in refresh_map
* -> if a key is pressed and released too quickly
* when refresh_map runs, the value of data->key is already at 0
* Therefore, the movement is also handled here
* the key is press -> we move now
*/
void	handle_directions(t_data *data, int keycode)
{
	if (keycode == KEY_W)
	{
		data->key.w = 1;
		move_forward_backward(data);
	}
	if (keycode == KEY_S)
	{
		data->key.s = 1;
		move_forward_backward(data);
	}
	if (keycode == KEY_A)
	{
		data->key.a = 1;
		move_left_right(data);
	}
	if (keycode == KEY_D)
	{
		data->key.d = 1;
		move_left_right(data);
	}
}

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC)
		close_esc(keycode, data);
	handle_directions(data, keycode);
	if (keycode == ARROW_LEFT)
	{
		data->key.left = 1;
		rotate_player(data);
	}
	if (keycode == ARROW_RIGHT)
	{
		data->key.right = 1;
		rotate_player(data);
	}
	return (0);
}

/*
* Set the key to 0 when it is released, so the movement stops
* Each key has its own state, allowing multiple keys to be
* pressed at the same time
* Example: turn left while moving forward
*/
int	handle_keyrelease(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_W)
		data->key.w = 0;
	if (keycode == KEY_S)
		data->key.s = 0;
	if (keycode == KEY_A)
		data->key.a = 0;
	if (keycode == KEY_D)
		data->key.d = 0;
	if (keycode == ARROW_LEFT)
		data->key.left = 0;
	if (keycode == ARROW_RIGHT)
		data->key.right = 0;
	return (0);
}

/*
* 1. detect if a key is pressed, which is and move, set key at 1
* 2. detect if a key is released, which, set key at 0
* 3. detect if the close window button is pressed
* 4. if key isn't realease, continue to move
*/
void	ft_init_hooks(t_data *data)
{
	mlx_hook(data->win, KEY_PRESS, 1L << 0, handle_keypress, data);
	mlx_hook(data->win, KEY_RELEASE, 1L << 1, handle_keyrelease, data);
	mlx_hook(data->win, EVENT_CLOSE, 0, close_window, data);
	mlx_loop_hook(data->mlx, refresh_map, data);
}
