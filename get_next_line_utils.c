/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:18:09 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/16 00:49:01 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_cline(char **content, char *nl, int index)
{
	int		i;
	int		j;
	char *new_content;

	if (index == -1)
	{
		*nl = '\0';
		return (0);
	}
	free(nl);
	nl = (char *)malloc(sizeof(char) * (index + 1));
	if (!nl)
		return (-1);
	new_content = (char *)malloc(sizeof(char) * (ft_strlen(*content) - index + 1));
	if (!new_content)
	{
		free(nl);
		return (-1);
	}
	i = 0;
	while ((*content)[i] != '\n')
	{
		nl[i] = (*content)[i];
		i++;
	}
	nl[i++] = '\0';
	j = 0;
	while ((*content)[i])
		new_content[j++] = (*content)[i++];
	new_content[j] = '\0';
	free((*content));
	*content = new_content;
	return (1);
}

char	*ft_join(char *s1, char *s2, int size)
{
	char	*rtn;
	char	*tmp;
	int		i;

	rtn = (char *)malloc(sizeof(char) * (size + 1));
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

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
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
