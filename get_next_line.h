/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:22:47 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/23 16:30:42 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "stdio.h"

char	*get_next_line(int fd);
int		main_while(int fd, char **newline_pos, char **remainder);
void	if_newline_pos(char **newline_pos, char **line, char **remainder);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);

#endif