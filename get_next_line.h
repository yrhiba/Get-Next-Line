/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:44:00 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/16 17:59:21 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_strchr(char *s);
char	*ft_join(char *s1, char *s2);
char	*get_next_line(int fd);
char	*read_content(char *content, int fd, int *r);

#endif
