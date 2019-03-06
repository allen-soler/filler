/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:56:57 by jallen            #+#    #+#             */
/*   Updated: 2019/03/06 21:04:13 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE1 10000

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);
int		simple_gnl(char **line);

#endif
