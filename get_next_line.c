/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:18:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/16 01:52:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content, int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->fd = fd;
	node->next = 0;
	return (node);
}

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

char	*ft_get_next_line(char *content, int fd, t_list *list)
{
	char	*nl;
	int		index;
	int		r;
	int		size;
	int		f;

	nl = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!nl)
		return (NULL);
	size = 0;
	r = 1;
	while (r)
	{
		f = ft_get_cline(&content, nl, ft_strchr(content, '\n'));
		if (f)
			break;
		else if (f == -1)
		{ 
			free(nl);
			return (NULL);
		}
		r = read(fd, nl, BUFFER_SIZE);
		if (r == -1)
		{
			free(nl);
			return (NULL);
		}
		nl[r] = '\0';
		size += r;
		content = ft_join(content, nl, size);
	}
	while (list)
	{
		if (list->fd == fd)
			list->content = content;
		list = list->next;
	}
	// printf("content : %s, size : %d, nl : %s\n", content, size, nl);
	return (nl);
}

char	*get_next_line(int fd)
{
	static t_list	*list = 0;
	char			*content;
	char			*line;
	
	content = ft_get_content(&list, fd);
	line = ft_get_next_line(content, fd, list);
	
	printf("nl : %s\n", line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*nl;

	fd = open("./file", O_RDONLY);
	
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);

	return (0);
}
