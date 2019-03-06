/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:38:45 by jallen            #+#    #+#             */
/*   Updated: 2019/03/06 22:20:53 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_get_player(t_fl *filler)
{
	char	*line;

	line = NULL;
	filler->player = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("$$$ exec p1", line, 11) == 0)
		{
			filler->player = 'O';
			filler->enemy = 'X';
			free(line);
			return (1);
		}
		else if (ft_strncmp("$$$ exec p2", line, 11) == 0)
		{
			filler->player = 'X';
			filler->enemy = 'O';
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

static void	map_int(t_fl *filler)
{
	int	i;
	int	j;

	i = -1;
	if (!(filler->int_map = (int **)malloc(sizeof(int *) * filler->axis.y)))
		return ;
	while (filler->map[++i])
	{
		if (!(filler->int_map[i] = (int *)malloc(sizeof(int) * filler->axis.x)))
			return ;
		j = -1;
		while (filler->map[i][++j])
		{
			if (filler->map[i][j] == '.')
				filler->int_map[i][j] = 0;
			else if (filler->map[i][j] == filler->player\
					|| filler->map[i][j] == filler->player + 32)
				filler->int_map[i][j] = -1;
			else if (filler->map[i][j] == filler->enemy\
					|| filler->map[i][j] == filler->enemy + 32)
				filler->int_map[i][j] = -2;
		}
	}
}

static int	get_map(t_fl *filler)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (get_next_line(0, &line) < 0)
		return (0);
	free(line);
	if (!(filler->map = (char **)malloc(sizeof(char *) * (filler->axis.y + 1))))
		return (0);
	while (i < filler->axis.y && get_next_line(0, &line) > 0)
	{
		filler->map[i] = ft_strdup(&line[4]);
		if ((int)ft_strlen(filler->map[i]) != filler->axis.x)
			return (0);
		free(line);
		i++;
	}
	if (i != filler->axis.y)
		return (0);
	filler->map[i] = NULL;
	map_int(filler);
	free_array(filler->map);
	return (1);
}

static int	get_piece(t_fl *filler, int i, int j)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("Piece", line, 5) == 0)
		{
			filler->vef_piece = ft_split_whitespaces(line);
			if (!(filler->piece = (char **)malloc(sizeof(char *)\
							* (ft_atoi(filler->vef_piece[1]) + 1))))
				return (0);
			free(line);
			while (++j < ft_atoi(filler->vef_piece[1]) && get_next_line(0, &line) > 0)
			{
				filler->piece[i] = ft_strdup(line);
				i++;
				free(line);
			}
			filler->piece[i] = NULL;
		}
		else
			return (0);
	}
	return (1);
}

int			ft_parsing(t_fl *filler)
{
	char	*line;
	char	**tab;

	tab = NULL;
	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("Plateau", line, 7) == 0)
		{
			tab = ft_split_whitespaces(line);
			free(line);
			filler->axis.y = ft_atoi(tab[1]);
			filler->axis.x = ft_atoi(tab[2]);
			free_array(tab);
			if (get_map(filler) == 0)
				return (msg_error());
		}
	}
	if (get_piece(filler, 0, -1) == 0)
		return (0);
	return (1);
}
