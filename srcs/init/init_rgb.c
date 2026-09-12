/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:41:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/09/12 09:40:39 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

static int	set_colors(t_data *data, char **ceiling, char **ground)
{
	data->ceiling.r = secure_rgb(ft_atol(ceiling[0]));
	data->ceiling.g = secure_rgb(ft_atol(ceiling[1]));
	data->ceiling.b = secure_rgb(ft_atol(ceiling[2]));
	data->ground.r = secure_rgb(ft_atol(ground[0]));
	data->ground.g = secure_rgb(ft_atol(ground[1]));
	data->ground.b = secure_rgb(ft_atol(ground[2]));
	if (data->ceiling.r == -1 || data->ceiling.g == -1
		|| data->ceiling.b == -1 || data->ground.r == -1
		|| data->ground.g == -1 || data->ground.b == -1)
		return (1);
	data->ceiling.color = create_trgb(0, data->ceiling.r,
			data->ceiling.g, data->ceiling.b);
	data->ground.color = create_trgb(0, data->ground.r,
			data->ground.g, data->ground.b);
	return (0);
}

int	init_rgb(t_data *data)
{
	char	**ground;
	char	**ceiling;
	int		error;

	if (check_double_rgb(data, "F") || check_double_rgb(data, "C"))
		return (1);
	ground = ft_split_rgb(data, "F");
	if (!ground)
		return (1);
	ceiling = ft_split_rgb(data, "C");
	if (!ceiling)
	{
		free_map(ground);
		return (1);
	}
	error = set_colors(data, ceiling, ground);
	free_map(ground);
	free_map(ceiling);
	return (error);
}
