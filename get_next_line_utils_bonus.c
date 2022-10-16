/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:44:30 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/16 17:05:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_content(char *content, int fd, int *r)
{
	char	c[BUFFER_SIZE + 1];

	*c = '\0';
	*r = read(fd, c, BUFFER_SIZE);
	if (*r == -1)
	{
		free(content);
		return (NULL);
	}
	c[*r] = '\0';
	if (*c)
		content = ft_join(content, c);
	return (content);
}

char	*ft_join(char *s1, char *s2)
{
	char	*rtn;
	char	*tmp;
	int		i;

	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rtn)
		return (NULL);
	tmp = rtn;
	i = 0;
	while (s1[i])
		*tmp++ = s1[i++];
	i = 0;
	while (s2[i])
		*tmp++ = s2[i++];
	*tmp = '\0';
	free(s1);
	return (rtn);
}

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
