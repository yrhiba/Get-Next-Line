/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:44:00 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/18 15:31:12 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

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
t_list				*ft_lstnew(char *content, int fd);
char				*ft_get_content(t_list **list_o, int fd);

#endif
