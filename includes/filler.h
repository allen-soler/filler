/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:01:49 by jallen            #+#    #+#             */
/*   Updated: 2019/03/04 16:21:05 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "../libftprintf/includes/ft_printf.h"
# include <errno.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_fl
{
	int			player;
	int			enemy;
	char		piece;
	char		**map;
	int			**int_map;
	int			height;
	t_point		axis;
}				t_fl;

/*
** Parsing Done
*/
void	ft_get_player(int *ret, int *fd, t_fl *filler);
void	map_int(t_fl *filler);
int		get_map(t_fl *filler, int *ret, int *fd);
int		ft_parsing(int *ret, int *fd, t_fl *filler);
void	ft_heatmap(t_fl *filler);

#endif
