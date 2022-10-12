/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:18:09 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/12 18:10:59 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2, size_t size)
{
	char	*rtn;
	char	*tmp;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	rtn = (char *) malloc (sizeof(char) * size);
	if (!rtn)
		return (0);
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
