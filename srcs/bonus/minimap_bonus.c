/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:35:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/09/13 12:57:10 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
// calcul de cellule
#ifdef BONUS
int cell_size(int x)
{

}
// remplir un carré de cellule * cellule à une position
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
