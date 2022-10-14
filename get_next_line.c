/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:18:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/14 16:03:01 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_content(t_list *list, int fd)
{
	char	*rtn;
	
	if (list)
	{
		while (list->next)
		{
			if (list->fd == fd)
				return (list->content);
			list = list->next;
		}
	}
	rtn = (char *)malloc (sizeof(char));
	*rtn = '\0';
	return (rtn);
}

char	*ft_get_next_line(char *content, int fd)
{
	char	*nl;

	
}

char	*get_next_line(int fd)
{
	static  t_list	*list;
	char			*content;
	char			*line;
	
	content = ft_get_content(list, fd);
	line = ft_get_next_line(content, fd);

	
	return (NULL);
}

int main()
{
	int fd = open("./file", O_WRONLY);
	char *nl = get_next_line(fd);

	printf("%s\n", nl);
	return 0;
}

