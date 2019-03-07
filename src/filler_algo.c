/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:16:04 by jallen            #+#    #+#             */
/*   Updated: 2019/03/07 18:18:09 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print_matrix(int **m, t_point size)
{
	t_point p;

	p.y = 0;
	while (p.y < size.y)
	{
		p.x = 0;
		while (p.x < size.x)
		{
			ft_fprintf(2, "%-3d", m[p.y][p.x]);
			p.x += 1;
		}
		ft_fprintf(2, "\n");
		p.y += 1;
	}
}

void		pos_cal(t_fl *filler, t_point p, t_point tab, t_point *pos)
{
	t_point	axis;
	int	counter;
	int	score;
	int valid;

	axis.y = 0;
	counter = 0;
	score = 0;
	valid = 1;
	while (axis.y < tab.y)
	{
		axis.x = 0;
		while (axis.x < tab.x)
		{
			if (filler->piece[axis.y][axis.x] == '*')
			{
				if (filler->int_map[p.y + axis.y][p.x + axis.x] == -1)
					counter++;
				else if (filler->int_map[p.y + axis.y][p.x + axis.x] == -2)
					valid = 0;
				else
					score += filler->int_map[p.y + axis.y][p.x + axis.x];
			}
			axis.x++;
		}
		axis.y++;
	}
	if (valid && counter == 1 && (filler->score == 0 || filler->score > score))
	{
		filler->score = score;
		pos->x = p.x;
		pos->y = p.y;
	}
}

int		filler_algo(t_fl *filler)
{
	t_point	p;
	t_point	tab;
	t_point	pos;

	filler->score = 0;
	tab.x = ft_atoi(filler->vef_piece[2]);
	tab.y = ft_atoi(filler->vef_piece[1]);
	p.y = 0;
	pos.x = 0;
	pos.y = 0;
	while (p.y < filler->axis.y)
	{
		p.x = 0;
		while (p.x < filler->axis.x)
		{
			if (p.x + tab.x < filler->axis.x && p.y + tab.y < filler->axis.y)
				pos_cal(filler, p, tab, &pos);
			p.x++;
		}
		p.y++;
	}
	free_array(filler->vef_piece);
	free_array(filler->piece);
	free_intray(filler->int_map, filler->axis.y);
	if (pos.y == 0 && pos.x == 0)
	{
		ft_printf("%d %d\n", pos.y, pos.x);
		return (0);
	}
	ft_printf("%d %d\n", pos.y, pos.x);
	return (1);
}
