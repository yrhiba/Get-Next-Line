/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:43:40 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/16 17:11:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// # define BUFFER_SIZE 5

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}					t_list;

int					ft_strlen(const char *s);
int					ft_strchr(char *s);
char				*ft_join(char *s1, char *s2);
char				*get_next_line(int fd);
char				*read_content(char *content, int fd, int *r);
t_list				*ft_lstnew(char *content, int fd);

#endif
