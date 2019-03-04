/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:32:30 by jallen            #+#    #+#             */
/*   Updated: 2019/03/04 19:32:34 by jallen           ###   ########.fr       */
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

void	init_heatmap(t_fl *filler, int x, int y, t_point p)
{
	if (y - 1 >= 0 && filler->int_map[y - 1][x] == 0)
		filler->int_map[y - 1][x] = 1;
	if (y - 1 >= 0 && p.x > x + 1 && filler->int_map[y - 1][x + 1] == 0)
		filler->int_map[y - 1][x + 1] = 1;
	if (p.x > x + 1 && filler->int_map[y][x + 1] == 0)
		filler->int_map[y][x + 1] = 1;
	if (p.y > y + 1 && p.x > x + 1 && filler->int_map[y + 1][x + 1] == 0)
		filler->int_map[y + 1][x + 1] = 1;
	if (p.y > y + 1 && filler->int_map[y + 1][x] == 0)
		filler->int_map[y + 1][x] = 1;
	if (p.y > y + 1 && x - 1 >= 0 && filler->int_map[y + 1][x - 1] == 0)
		filler->int_map[y + 1][x - 1] = 1;
	if (x - 1 >= 0 && filler->int_map[y][x - 1] == 0)
		filler->int_map[y][x - 1] = 1;
	if (y - 1 >= 0 && x - 1 >= 0 && filler->int_map[y - 1][x - 1] == 0)
		filler->int_map[y - 1][x - 1] = 1;
}

void	pos_heatmap(t_fl *filler, int x, int y, int index)
{
	t_point	p;

	p.y = filler->axis.y;
	p.x = filler->axis.x;
	if (y - 1 >= 0 && filler->int_map[y - 1][x] == 0)
		filler->int_map[y - 1][x] = index + 1;
	if (y - 1 >= 0 && p.x > x + 1 && filler->int_map[y - 1][x + 1] == 0)
		filler->int_map[y - 1][x + 1] = index + 1;
	if (p.x > x + 1 && filler->int_map[y][x + 1] == 0)
		filler->int_map[y][x + 1] = index + 1;
	if (p.y > y + 1 && p.x > x + 1 && filler->int_map[y + 1][x + 1] == 0)
		filler->int_map[y + 1][x + 1] = index + 1;
	if (p.y > y + 1 && filler->int_map[y + 1][x] == 0)
		filler->int_map[y + 1][x] = index + 1;
	if (p.y > y + 1 && x - 1 >= 0 && filler->int_map[y + 1][x - 1] == 0)
		filler->int_map[y + 1][x - 1] = index + 1;
	if (x - 1 >= 0 && filler->int_map[y][x - 1] == 0)
		filler->int_map[y][x - 1] = index + 1;
	if (y - 1 >= 0 && x - 1 >= 0 && filler->int_map[y - 1][x - 1] == 0)
		filler->int_map[y - 1][x - 1] = index + 1;
}

void	max_heatmap(t_fl *filler, t_point size)
{
	t_point	p;
	int		i;

	i = 1;
	while (i < size.x)
	{
		p.y = 0;
		while (p.y < size.y)
		{
			p.x = 0;
			while (p.x < size.x)
			{
				if (filler->int_map[p.y][p.x] == i)
					pos_heatmap(filler, p.x, p.y, i);
				p.x++;
			}
			p.y++;
		}
		i++;
	}
}

void	ft_heatmap(t_fl *filler)
{
	int	i;
	int	j;

	i = 0;
	while (i < filler->axis.y)
	{
		j = 0;
		while (j < filler->axis.x)
		{
			if (filler->int_map[i][j] == -2)
				init_heatmap(filler, j, i, filler->axis);
			j++;
		}
		i++;
	}
	max_heatmap(filler, filler->axis);
	print_matrix(filler->int_map, filler->axis);
}
