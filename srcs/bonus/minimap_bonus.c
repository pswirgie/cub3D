/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:35:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/09/13 14:36:15 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#ifdef BONUS

// calcul de cellule
int	cell_size(t_data *data)
{
	int	lines;
	int	columns;
	int	cell;
	int	max_dim;

	lines = data->map.lines;
	columns = data->map.columns;
	max_dim = lines;
	if (columns > lines)
		max_dim = columns;
	cell = MINI_MAX / max_dim;
	if (cell < 1)
		cell = 1;
	return (cell);
}

// remplir un carré de cellule * cellule à une position
void	draw_cell(t_data *data, int sx, int sy, int color)
{
	int	cell;
	int	dy;
	int	dx;

	cell = cell_size(data);
	dy = 0;
	while (dy < cell)
	{
		dx = 0;
		while (dx < cell)
		{
			put_pixel(data, sy + dy, sx + dx, color);
			dx++;
		}
		dy++;
	}
}

void	draw_all_cells(t_data *data, int cell)
{
	int	row;
	int	col;
	int	sx;
	int	sy;

	row = 0;
	while (data->map.maze[row])
	{
		col = 0;
		while (data->map.maze[row][col])
		{
			sx = MINI_MARGIN + col * cell;
			sy = MINI_MARGIN + row * cell;
			if (data->map.maze[row][col] == '1' ||
				data->map.maze[row][col] == 'X')
				draw_cell(data, sx, sy, MINI_WALL);
			else
				draw_cell(data, sx, sy, MINI_FLOOR);
			col++;
		}
		row++;
	}
}

void	draw_minimap(t_data *data)
{
	double	px;
	double	py;
	int		cell;
	int		i;

	cell = cell_size(data);
	px = MINI_MARGIN + data->player.pos_x * cell;
	py = MINI_MARGIN + data->player.pos_y * cell;
	draw_all_cells(data, cell);
	draw_cell(data, (int)px, (int)py, MINI_PLAYER);
	i = 0;
	while (i < 4 * cell)
	{
		put_pixel(data, (int)py + data->player.dir_x * i + 3,
			(int)px + data->player.dir_y * i + 3, MINI_PLAYER);
		i++;
	}
}

#else

void	draw_minimap(t_data *data)
{
	(void)data;
}
#endif
