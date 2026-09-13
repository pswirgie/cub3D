/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:35:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/09/13 13:49:42 by nbaudoin         ###   ########.fr       */
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

void draw_all_cells(t_data *data)
{
	int max_row;
	int max_col;
	int row;
	int	col;

	max_row = data->map.lines;
	max_col = data->map.columns;
	row = 0;
	while(row < max_row)
	{
		col = 0;
		while (col < max_col)
		{
			if (data->map.maze[row][col] == 1)
				draw_cell(data, row, col, MINI_WALL);
			else if (data->map.maze[row][col] == 0)
				draw_cell(data, MINI_MARGIN + row, MINI_MARGIN + col, MINI_FLOOR);
			col++;
		}
		row++;
	}
}

void	draw_minimap(t_data *data)
{

	draw_all_cells(data); // un carré rouge à (colonne 50, ligne 50)
}

// func qui parcourt et appell le remplissage carré avec la bnne couleur
// func dessine le joueur : carré/point à MARGIN + pos * cell
// draw minimap qui orchestre

// on l'appelle dans render() - > raycasting.c

#else

void	draw_minimap(t_data *data)
{
	(void)data;
}
#endif
