/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:46:22 by tbartocc          #+#    #+#             */
/*   Updated: 2024/10/18 17:11:13 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	close_p(int **pipes, int index)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		if (i == index)
			close(pipes[i][0]);
		else if (index >= 0 && i == (index - 1))
			close(pipes[i][1]);
		else
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
		}
		++i;
	}
}

void	free_p(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		free(pipes[i]);
		++i;
	}
	free(pipes);
}

void	free_all_and_exit_1(int **pipes, t_fd *fd)
{
	free_p(pipes);
	free(fd->fd);
	free(fd);
	exit(1);
}

int	**open_pipes(int nbr_pipes)
{
	int	**pipes;
	int	i;

	pipes = ft_calloc(nbr_pipes + 1, sizeof(int *));
	if (!pipes)
		return (0);
	i = 0;
	while (i < nbr_pipes)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (pipe(pipes[i]) < 0)
		{
			close_p(pipes, -1);
			free_p(pipes);
			return (0);
		}
		++i;
	}
	return (pipes);
}
