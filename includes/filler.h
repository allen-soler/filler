/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:01:49 by jallen            #+#    #+#             */
/*   Updated: 2019/03/05 23:35:48 by jallen           ###   ########.fr       */
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
	char		*vef_piece;
	char		**piece;
	char		**map;
	int			**int_map;
	t_point		axis;
}				t_fl;

/*
** Parsing
*/
int		ft_parsing(t_fl *filler);
int		ft_get_player(t_fl *filler);
/*
** Heatmap && Algo
*/
void	ft_heatmap(t_fl *filler);
void	filler_algo(t_fl *filler);
/*
** Errors
*/
int		msg_error(void);

#endif
