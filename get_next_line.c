/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:43:18 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/17 18:10:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_content(char *content, int fd, int *r)
{
	char	*c;

	c = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!c)
	{
		free(content);
		return (NULL);
	}
	*c = '\0';
	*r = read(fd, c, BUFFER_SIZE);
	if (*r == -1)
	{
		free(c);
		free(content);
		return (NULL);
	}
	c[*r] = '\0';
	if (*c)
		content = ft_join(content, c);
	free(c);
	return (content);
}

void	get_line_3(char *content, char *nw_content, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	j = 0;
	while (content[i])
		nw_content[j++] = content[i++];
	nw_content[j] = '\0';
}

char	*get_line_2(char **content, int index)
{
	char	*line;
	char	*nw_content;

	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	nw_content = (char *)malloc(sizeof(char) * (ft_strlen(*content) - index));
	if (!nw_content)
	{
		free(line);
		return (NULL);
	}
	get_line_3(*content, nw_content, line);
	free(*content);
	*content = nw_content;
	return (line);
}

char	*get_line_1(char **content, int fd)
{
	char	*line;
	int		r;

	r = 1;
	line = (char *)malloc(sizeof(char));
	*line = '\0';
	while (*content && ft_strchr(*content) == -1 && r != 0)
		*content = read_content(*content, fd, &r);
	if (!*content)
	{
		free(line);
		return (NULL);
	}
	if (r == 0)
	{
		line = ft_join(line, *content);
		free(*content);
		*content = 0;
		return (line);
	}
	free(line);
	line = get_line_2(content, ft_strchr(*content));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*tmp;
	char			*content;
	char			*line;

	if (fd < 0)
		return (NULL);
	content = ft_get_content(&list, fd);
	if (!content)
		return (NULL);
	line = get_line_1(&content, fd);
	tmp = list;
	while (tmp)
	{
		if (tmp->fd == fd)
			tmp->content = content;
		tmp = tmp->next;
	}
	return (line);
}
