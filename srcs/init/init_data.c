/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/09/12 09:26:05 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"

static int	load_textures(t_data *data)
{
	if (load_image(data, &data->north) || load_image(data, &data->south)
		|| load_image(data, &data->east) || load_image(data, &data->weast))
		return (1);
	return (0);
}


static void	*init_window(t_data *data)
{
	void	*ptr;

	data->height = HEIGHT_WINDOW;
	data->width = WIDTH_WINDOW;
	ptr = mlx_new_window(data->mlx, data->width, data->height, "cub3D");
	return (ptr);
}

int	ft_init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_mlx_error();
		return (1);
	}
	mlx_do_key_autorepeatoff(data->mlx);
	if (load_textures(data))
		return (1);
	data->win = init_window(data);
	if (!data->win)
	{
		ft_mlx_error();
		return (1);
	}
	ft_init_hooks(data);
	if (init_render(data))
		return (1);
	return (0);
}

static int	get_all_directions(t_data *data)
{
	data->north.path = get_direction(data, "NO");
	if (!data->north.path)
		return (1);
	data->south.path = get_direction(data, "SO");
	if (!data->south.path)
		return (1);
	data->weast.path = get_direction(data, "WE");
	if (!data->weast.path)
		return (1);
	data->east.path = get_direction(data, "EA");
	if (!data->east.path)
		return (1);
	return (0);
}

int	ft_init_data(t_data *data)
{
	if (init_full_file(data))
		return (1);
	if (is_tabs(data->map.full_file))
		return (1);
	if (get_all_directions(data))
		return (1);
	if (init_rgb(data))
		return (1);
	if (init_maze(data))
		return (1);
	if (is_valid_maze(data))
		return (1);
	return (0);
}
