/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:16:04 by jallen            #+#    #+#             */
/*   Updated: 2019/03/08 12:25:20 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	check_algo(t_fl *filler, t_tools t, t_point p, t_point *pos)
{
	if (t.valid && t.counter == 1
			&& (filler->score == 0 || filler->score > t.score))
	{
		filler->score = t.score;
		pos->x = p.x;
		pos->y = p.y;
	}
}

static void	pos_cal(t_fl *filler, t_point p, t_point tab, t_point *pos)
{
	t_tools	t;

	t.axis.y = 0;
	t.counter = 0;
	t.valid = 1;
	t.score = 0;
	while (t.axis.y < tab.y)
	{
		t.axis.x = 0;
		while (t.axis.x < tab.x)
		{
			if (filler->piece[t.axis.y][t.axis.x] == '*')
			{
				if (filler->int_map[p.y + t.axis.y][p.x + t.axis.x] == -1)
					t.counter++;
				else if (filler->int_map[p.y + t.axis.y][p.x + t.axis.x] == -2)
					t.valid = 0;
				else
					t.score += filler->int_map[p.y + t.axis.y][p.x + t.axis.x];
			}
			t.axis.x++;
		}
		t.axis.y++;
	}
	check_algo(filler, t, p, pos);
}

void		filler_algo(t_fl *filler, t_point *pos)
{
	t_point	p;
	t_point	tab;

	filler->score = 0;
	tab.x = ft_atoi(filler->vef_piece[2]);
	tab.y = ft_atoi(filler->vef_piece[1]);
	p.y = 0;
	while (p.y < filler->axis.y)
	{
		p.x = 0;
		while (p.x < filler->axis.x)
		{
			if (p.x + tab.x < filler->axis.x && p.y + tab.y < filler->axis.y)
				pos_cal(filler, p, tab, pos);
			p.x++;
		}
		p.y++;
	}
}
