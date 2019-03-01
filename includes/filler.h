/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:54:16 by jallen            #+#    #+#             */
/*   Updated: 2019/03/01 18:27:58 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "../libftprintf/includes/ft_printf.h"
# include <errno.h>

typedef struct	s_points
{
	int			x;
	int			y;
}				t_points;

typedef struct	s_fl
{
	int			player;
	int			piece;
	char		**map;
	int			height;
	t_points	axis;
}				t_fl;

#endif
