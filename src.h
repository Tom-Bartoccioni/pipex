/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:26 by tbartocc          #+#    #+#             */
/*   Updated: 2024/10/11 11:57:09 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "./Printf/printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_fd
{
	int		*fd;
	int		fd_h;
}	t_fd;

void	close_p(int **pipes, int index);
void	exec(char *cmd, char **env, int **pipes, t_fd *fd);
void	free_p(int **pipes);
char	*get_next_line(int fd);
char	*get_path(char *cmd, char **env);
void	here_doc_put_in(char **av, int fd);
int		**open_pipes(int nbr_pipes);
int		wait_children(int *pid);

// int		open_file(char *file, int in_or_out);

#endif
