/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:18:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/14 17:45:46 by yrhiba           ###   ########.fr       */
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

	if (*list)
	{
		while ((*list)->next)
		{
			if ((*list)->fd == fd)
				return ((*list)->content);
			(*list) = (*list)->next;
		}
	}
	rtn = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	new = ft_lstnew(rtn, fd);
	if (!rtn || !new)
		return (NULL);
	*rtn = '\0';
	new->next = *list;
	*list = new;
	return ((*list)->content);
}

char	*ft_get_next_line(char *., int fd, t_list *list)
{
	char	*nl;
	int		index;
	int		r;
	int		size;

	nl = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!nl)
		return (NULL);
	r = ft_get_cline(content, nl, ft_strchr(content, '\n')) if (r) return (nl);
	else if (r == -1) return (NULL);
	r = 1;
	while (r)
	{
		r = read(fd, nl, BUFFER_SIZE);
		if (r == -1)
		{
			free(nl);
			return (NULL);
		}
		nl[r] = '\0';
		size += r;
		nl = ft_join(content, nl, size);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*content;
	char			*line;

	list = 0;
	content = ft_get_content(&list, fd);
	line = ft_get_next_line(content, fd, list);
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*nl;

	fd = open("./file", O_WRONLY);
	nl = get_next_line(fd);
	printf("%s\n", nl);
	return (0);
}
