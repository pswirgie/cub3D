/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/09/12 11:01:57 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>

static void	try_push(t_data *data, t_flood *f, int y, int x)
{
	int	lines;

	lines = data->map.lines + 1;
	if (y < 0 || x < 0 || y > lines || x >= data->map.columns
		|| data->map.maze[y][x] == '1'
		|| data->map.maze[y][x] == 'G'
		|| data->map.maze[y][x] == '\n')
		return ;
	if (data->map.maze[y][x] == 'X')
		data->map.wall_missing++;
	data->map.maze[y][x] = 'G';
	f->stack[f->top] = y * f->cols + x;
	f->top++;
}

static int	find_path(t_data *data, int start_y, int start_x)
{
	t_flood	f;
	int		pos;
	int		y;
	int		x;

	f.cols = data->map.columns;
	f.stack = malloc(sizeof(int) * (data->map.lines + 2) * f.cols);
	if (!f.stack)
		return (1);
	f.top = 0;
	try_push(data, &f, start_y, start_x);
	while (f.top > 0)
	{
		pos = f.stack[--f.top];
		y = pos / f.cols;
		x = pos % f.cols;
		try_push(data, &f, y + 1, x);
		try_push(data, &f, y - 1, x);
		try_push(data, &f, y, x + 1);
		try_push(data, &f, y, x - 1);
	}
	free(f.stack);
	return (0);
}

static void	ft_index_find(char *str, char c, int *index)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (i >= ft_strlen(str))
	{
		*index = -1;
		return ;
	}
	*index = i;
}

static int	is_surrounded(t_data *data, int *err)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map.maze[y])
	{
		if (data->map.wall_missing)
			return (1);
		ft_index_find(data->map.maze[y], '0', &x);
		if (x != -1)
		{
			if (find_path(data, y, x))
			{
				*err = 1;
				return (1);
			}
			y = 0;
		}
		else
			y++;
	}
	return (0);
}

int	check_walls(t_data *data)
{
	int	err;

	err = 0;
	if (find_path(data, data->player.y_start_p, data->player.x_start_p))
	{
		ft_display_error("check_walls - allocation failed");
		return (1);
	}
	if (is_surrounded(data, &err))
	{
		if (err)
			ft_display_error("check_walls - allocation failed");
		else
			ft_display_error("At least one wall is missing");
		return (1);
	}
	return (0);
}
