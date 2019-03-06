/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:16:04 by jallen            #+#    #+#             */
/*   Updated: 2019/03/06 22:23:03 by jallen           ###   ########.fr       */
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
			ft_printf("%-3d", m[p.y][p.x]);
			p.x += 1;
		}
		ft_printf("\n");
		p.y += 1;
	}
}

void		pos_cal(t_fl *filler, t_point p, t_point tab, t_point *pos)
{
	t_point	axis;
	int	counter;
	int	score;

	axis.y = 0;
	counter = 0;
	score = 0;
	while (axis.y < tab.y && p.y + axis.y < filler->axis.y)
	{
		axis.x = 0;
		while (axis.x < tab.x && p.x + axis.x < filler->axis.x)
		{
			if (filler->piece[axis.y][axis.x] == '*')
			{
				if (filler->int_map[p.y + axis.y][p.x + axis.x] == -1)
				{	
					counter++;
					if (counter > 1)
						return ;
					else if (filler->int_map[p.y + axis.y][p.x + axis.x] == -2)
						return ;
					else
						score = filler->int_map[p.y][p.x] + score;
						pos->x = p.x;
						pos->y = p.y;
				}
			}
			axis.x++;
		}
		axis.y++;
	}

	if (filler->score == 0 || filler->score > score)
		filler->score = score;
}

void	filler_algo(t_fl *filler, t_point *pos)
{
	t_point	p;
	t_point	tab;

	filler->score = filler->axis.x;
	tab.x = ft_atoi(filler->vef_piece[2]);
	tab.y = ft_atoi(filler->vef_piece[1]);
	p.y = 0;
	while (p.y < filler->axis.y)
	{
		p.x = 0;
		while (p.x < filler->axis.x)
		{
			pos_cal(filler, p, tab, pos);
			p.x++;
		}
		p.y++;
	}
	ft_putnbr(pos->y);
	ft_putchar(' ');
	ft_putnbr(pos->x);
	ft_putchar('\n');
}
