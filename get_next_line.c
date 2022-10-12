/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:18:28 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/12 18:09:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_sread(int fd)
{
	char	*fcontent;
	char	*c;
	int		r;
	size_t	size;

	size = 0;
	c = (char *)malloc(sizeof(char) + 1);
	if (!c)
		return (0);
	r = 1;
	while (c[0] != '\n' || c[0] != '\0')
	{
		r = read(fd, &c, 1);
		c[r] = '\0';
		size += r;
		fcontent = ft_join(fcontent, c, (size + 1));
	}
}

char	*ft_fread(int fd)
{
	char	*fcontent;
	char	*c;
	int		r;
	size_t	size;

	size = 0;
	fcontent = (char *) malloc (sizeof(char));
	*fcontent = '\0';
	c = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!c)
		return (0);
	r = 1;
	while (r)
	{
		r = read(fd, &c, BUFFER_SIZE);
		c[r] = '\0';
		size += r;
		fcontent = ft_join(fcontent, c, (size + 1));
	}
}

char	*get_next_line(int fd)
{
	static size_t	dl = 0;
	char			*fcontent;

	fcontent = ft_fread(fd);
	if (!fcontent)
		return (0);
	return (fcontent);
}

int main(int argc, char const *argv[])
{
	printf("|%s|\n", get_next_line(0));
	return 0;
}
