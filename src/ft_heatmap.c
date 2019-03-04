/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:32:30 by jallen            #+#    #+#             */
/*   Updated: 2019/03/04 18:36:51 by jallen           ###   ########.fr       */
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

void	pos_heatmap(t_fl *filler, int x, int y, t_point p)
{
	ft_fprintf(2, "%i %i\n", y, x);
	if (y - 1 >= 0 && filler->int_map[y - 1][x] == 0) // up 
		filler->int_map[y - 1][x] = 1;
	if (y - 1 >= 0 && p.x > x + 1 && filler->int_map[y - 1][x + 1] == 0) //up right 
		filler->int_map[y - 1][x + 1] = 1;
	if (p.x > x + 1 && filler->int_map[y][x + 1] == 0) //center right
		filler->int_map[y][x + 1] = 1;
	if (p.y > y + 1 && p.x > x + 1 && filler->int_map[y + 1][x + 1] == 0) //down right
		filler->int_map[y + 1][x + 1] = 1;
	if (p.y > y + 1 && filler->int_map[y + 1][x] == 0) //center down
		filler->int_map[y + 1][x] = 1;
	if (p.y > y + 1 && x - 1 >= 0 && filler->int_map[y + 1][x - 1] == 0) //left down
		filler->int_map[y + 1][x - 1] = 1;
	if (x - 1 >= 0 && filler->int_map[y][x - 1] == 0) //center left
		filler->int_map[y][x - 1] = 1;
	if (y - 1 >= 0 && x - 1 >= 0 && filler->int_map[y - 1][x - 1] == 0) //up left
		filler->int_map[y - 1][x - 1] = 1;
}

void	set_min(t_fl *filler, t_point size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (filler->int_map[i][j] == -2)
				pos_heatmap(filler, j, i, size);
			j++;
		}
		i++;	
	}
	print_matrix(filler->int_map, filler->axis);
}

void	ft_heatmap(t_fl *filler)
{
	set_min(filler, filler->axis);
}
