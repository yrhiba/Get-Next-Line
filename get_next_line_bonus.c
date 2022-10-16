/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:45:32 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/16 17:44:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_content(t_list **list, int fd)
{
	t_list	*new;
	char	*rtn;

	while (*list)
	{
		if ((*list)->fd == fd)
			return ((*list)->content);
		*list = (*list)->next;
	}
	rtn = (char *)malloc(sizeof(char));
	if (!rtn)
		return (NULL);
	*rtn = '\0';
	new = ft_lstnew(rtn, fd);
	if (!new)
	{
		free(rtn);
		return (NULL);
	}
	new->next = *list;
	*list = new;
	return ((*list)->content);
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
	while (ft_strchr(*content) == -1 && r != 0)
		*content = read_content(*content, fd, &r);
	if (!*content)
		return (NULL);
	if (ft_strchr(*content) == -1)
		return (NULL);
	line = get_line_2(content, ft_strchr(*content));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list = 0;
	t_list			*tmp;
	char			*content;
	char			*line;

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
