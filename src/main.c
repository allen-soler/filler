/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:47:35 by jallen            #+#    #+#             */
/*   Updated: 2019/03/02 21:57:38 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_player(int *ret, int *fd, t_fl *filler)
{
	char	*line;

	line = NULL;
	filler->player = 0;
	if ((*ret = get_next_line(*fd, &line)) == 1)
	{
		if (ft_strncmp("$$$ exec p1", line, 11) == 0)
		{
			filler->player = 1;
			filler->piece = 'o';
		}
		else if (ft_strncmp("$$$ exec p2", line, 11) == 0)
		{
			filler->player = 2;
			filler->piece = 'x';
		}
		free(line);
	}
}

void	map_int(t_fl *filler)
{
	while (*filler->map && filler->map)
	{
		
	}
}

void	get_map(t_fl *filler, int *ret, int *fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	*ret = get_next_line(*fd, &line);
	free(line);
	if (!(filler->map = (char **)malloc(sizeof(char *) * filler->axis.y + 1)))
		return ;
	while (i < filler->axis.y)
	{
		*ret = get_next_line(*fd, &line);
		filler->map[i] = ft_strdup(&line[4]);
		ft_printf("MAP = %s\n", filler->map[i]);
		free(line);
		i++;
	}
	map_int(filler);
}

int		ft_parsing(int *ret, int *fd, t_fl *filler)
{
	char	*line;
	char	**tab;

	tab = NULL;
	line = NULL;
	while ((*ret = get_next_line(*fd, &line)) == 1)
	{
		if (ft_strncmp("Plateau", line, 7) == 0)
		{
			tab = ft_split_whitespaces(line);
			filler->axis.y = ft_atoi(tab[1]);
			filler->axis.x = ft_atoi(tab[2]);
			free_array(tab);
			get_map(filler, ret, fd);
		}
		if (ft_strncmp("Piece", line, 5) == 0)
			ft_printf("%s\n", line);
		free(line);
	}
}

int		main(int ac, char **av)
{
	t_fl	filler;
	int		fd;
	int		ret;

	(void)ac;
	ret = 0;
	fd = open(av[1], O_RDONLY);
	ft_get_player(&ret, &fd, &filler);
	if (filler.player != 0)
		ft_parsing(&ret, &fd, &filler);
	return (0);
}
