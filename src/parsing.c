/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:38:45 by jallen            #+#    #+#             */
/*   Updated: 2019/03/08 14:07:14 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_get_player(t_fl *filler)
{
	char	*line;

	line = NULL;
	filler->player = 0;
	if (gnl(0, &line) > 0)
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
	if (gnl(0, &line) < 0)
		return (0);
	free(line);
	if (!(filler->map = (char **)malloc(sizeof(char *) * (filler->axis.y + 1))))
		return (0);
	while (i < filler->axis.y && gnl(0, &line) > 0)
	{
		filler->map[i] = ft_strdup(&line[4]);
		if ((int)ft_strlen(filler->map[i]) != filler->axis.x)
			return (msg_error());
		free(line);
		i++;
	}
	if (i != filler->axis.y)
		return (msg_error());
	filler->map[i] = NULL;
	map_int(filler);
	free_array(filler->map);
	return (1);
}

static int	get_piece(t_fl *filler, char *src)
{
	char	*line;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = -1;
	line = NULL;
	filler->vef_piece = ft_split_whitespaces(src);
	size = ft_atoi(filler->vef_piece[1]);
	if (!(filler->piece = (char **)malloc(sizeof(char *) * (1 + size))))
		return (0);
	free(line);
	while (++j < size && gnl(0, &line) > 0)
	{
		filler->piece[i] = ft_strdup(line);
		i++;
		free(line);
	}
	filler->piece[i] = NULL;
	return (1);
}

void		ft_parsing(t_fl *filler)
{
	char	*line;

	filler->map = NULL;
	line = NULL;
	while (gnl(0, &line) > 0)
	{
		if (line && ft_strncmp("Plateau", line, 7) == 0)
		{
			filler->map = ft_split_whitespaces(line);
			filler->axis.y = ft_atoi(filler->map[1]);
			filler->axis.x = ft_atoi(filler->map[2]);
			free_array(filler->map);
			if (get_map(filler) == 0)
				return ;
		}
		else if (line && ft_strncmp("Piece", line, 5) == 0 && line)
		{
			get_piece(filler, line);
			if (ft_heatmap(filler) == 0)
				break ;
		}
		free(line);
	}
	if (line)
		free(line);
}
