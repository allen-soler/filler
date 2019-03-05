/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:16:04 by jallen            #+#    #+#             */
/*   Updated: 2019/03/05 23:37:35 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	print_matrix(int **m, t_point size)
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

int		pos_cal(t_fl *filler, t_point *pos, t_point p)
{
	(void)pos;
	ft_printf("inside %i\n", filler->int_map[p.x]);
	return (1);
}

void	filler_algo(t_fl *filler)
{
	t_point	p;
	t_point	pos;

	pos.y = 0;
	pos.x = 0;
	p.y = 0;
	ft_printf("%i\n", filler->player);
	while (p.y < filler->axis.y)
	{
		p.x = 0;
		while (p.x < filler->axis.x)
		{
			if (filler->int_map[p.y][p.x] == filler->player)
				pos_cal(filler, &pos, p);
			p.x++;
		}
		p.y++;
	}
	print_matrix(filler->int_map, filler->axis);
}
