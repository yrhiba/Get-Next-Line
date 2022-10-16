/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:18:41 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/15 02:32:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}					t_list;

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
char	*ft_join(char *s1, char *s2, int size);
int		ft_strlen(const char *s);
t_list	*ft_lstnew(char *content, int fd);
int	ft_get_cline(char **content, char *nl, int index);

#endif
