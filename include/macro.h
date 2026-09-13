/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:46:20 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/09/13 10:25:07 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

// @KEYS

# ifndef ARROW_LEFT
#  define ARROW_LEFT 65361
# endif

# ifndef ARROW_RIGHT
#  define ARROW_RIGHT 65363
# endif

# ifndef KEY_A
#  define KEY_A 97
# endif

# ifndef KEY_W
#  define KEY_W 119
# endif

# ifndef KEY_D
#  define KEY_D 100
# endif

# ifndef KEY_S
#  define KEY_S 115
# endif

// UI

# define WIDTH_WINDOW 1280
# define HEIGHT_WINDOW 720

# ifndef ESC
#  define ESC 65307
# endif

# ifndef EVENT_CLOSE
#  define EVENT_CLOSE 17
# endif

# define KEY_PRESS 2
# define KEY_RELEASE 3

// Math

# define FOV 90
# define MOVE_SPEED 20.00
# define ROT_SPEED 0.03

#endif
