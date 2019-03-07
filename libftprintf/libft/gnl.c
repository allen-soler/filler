/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:33:01 by jallen            #+#    #+#             */
/*   Updated: 2019/03/07 15:32:15 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "stdio.h"
static t_list	*get_current_file(t_list **file, const int fd)
{
	t_list	*ptr;

	ptr = *file;
	while (ptr)
	{
		if ((int)ptr->content_size == fd)
			return (ptr);
		ptr = ptr->next;
	}
	if (!(ptr = ft_lstnew("", fd)))
		return (NULL);
	ft_lstadd(file, ptr);
	ptr = *file;
	return (ptr);
}

static int		read_fd(const int fd, char **saved)
{
	char	buff[BUFF_SIZE + 1];
	int		n_read;
	char	*new_str;

	n_read = read(fd, buff, BUFF_SIZE);
	if (n_read > 0)
	{
		buff[n_read] = '\0';
		new_str = ft_strjoin(*saved, buff);
		if (!new_str)
			return (-1);
		free(*saved);
		*saved = new_str;
	}
	return (n_read);
}

static int		ft_new_line(t_list *curr, char **line, char *nl_index)
{
	*line = ft_strsub(curr->content, 0, nl_index - (char *)curr->content);
	if (!*line)
		return (-1);
	if (*nl_index != '\0')
		if (!(nl_index = ft_strdup(nl_index + 1)))
			return (-1);
	free(curr->content);
	curr->content = nl_index;
	return (1);
}

static int		handle_eof(t_list *curr)
{
	if (curr->content != NULL)
		free(curr->content);
	free(curr);
	return (0);
}

int				gnl(const int fd, char **line)
{
	static t_list	*file;
	t_list			*curr;
	char			*nl_index;
	int				ret;

	if (fd < -1 || line == NULL || BUFF_SIZE < 0 || read(fd, &ret, 0) < 0)
		return (-1);
	if (!(curr = get_current_file(&file, fd)))
		return (-1);
	nl_index = ft_strchr(curr->content, '\n');
	while (nl_index == NULL)
	{
		ret = read_fd(fd, (char **)&(curr->content));
		if (ret == 0)
		{
			if ((nl_index = ft_strchr(curr->content, '\0'))\
					== (char *)curr->content)
				return (handle_eof(curr));
		}
		else if (ret < 0)
			return (-1);
		else
			nl_index = ft_strchr(curr->content, '\n');
	}
	return (ft_new_line(curr, line, nl_index));
}
