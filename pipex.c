/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:34:21 by tbartocc          #+#    #+#             */
/*   Updated: 2024/10/11 11:59:56 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

/*
int	do_last_pipe(int fd_out, char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];
	int		status;

	status = 0;
	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		if (fd_out == -1)
			exit(1);
		close(p_fd[1]);
		dup2(fd_out, 1);
		exec(cmd, env);
	}
	else
		waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

void	do_pipe(int fd_in, char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
	{
		if (fd_in == -1)
			exit(1);
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		waitpid(pid, 0, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd_in;
	int	fd_out;

	if (ac < 5)
		return (ft_printf("./pipex infile cmd ... cmd outfile\n"), 1);
	if (!ft_strcmp(av[1], "here_doc"))
	{
		if (ac < 6)
			return (ft_printf("./pipex heredoc LIMITER cmd cmd outfile\n"), 1);
		i = 3;
		fd_out = open_file(av[ac - 1], 2);
		here_doc(av);
	}
	else
	{
		i = 2;
		fd_in = open_file(av[1], 0);
		fd_out = open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < ac - 2)
		do_pipe(fd_in, av[i++], env);
	return (do_last_pipe(fd_out, av[ac - 2], env));
}
*/

void	read_child(int **pipes, char **av, int index, t_fd *fd)
{
	int	nbr_cmd;

	nbr_cmd = ft_tablen(av) - 3;
	if (!ft_strcmp(av[1], "here_doc"))
		nbr_cmd = ft_tablen(av) - 4;
	close_p(pipes, index);
	if (fd->fd_h >= 0 && index > 0)
		close(fd->fd_h);
	if (index == 0)
	{
		if (fd->fd_h >= 0)
			fd->fd[0] = fd->fd_h;
		else
			fd->fd[0] = open(av[1], O_RDONLY);
	}
	else
		fd->fd[0] = pipes[index - 1][0];
	if (fd->fd[0] == -1)
	{
		close(pipes[index][1]);
		free_p(pipes);
		free(fd->fd);
		free(fd);
		exit(1);
	}
}

void	write_child(int **pipes, char **av, int index, t_fd *fd)
{
	int	nbr_cmd;

	nbr_cmd = ft_tablen(av) - 3;
	if (!ft_strcmp(av[1], "here_doc"))
		nbr_cmd = ft_tablen(av) - 4;
	if (index == (nbr_cmd - 1))
	{
		if (fd->fd_h >= 0)
			fd->fd[1] = open(av[ft_tablen(av) - 1],
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd->fd[1] = open(av[ft_tablen(av) - 1],
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
		fd->fd[1] = pipes[index][1];
	if (fd->fd[1] == -1)
	{
		close(fd->fd[0]);
		free_p(pipes);
		free(fd->fd);
		free(fd);
		exit(1);
	}
}

void	execute_child(t_fd *fd, char *cmd, char **env, int **pipes)
{
	dup2(fd->fd[0], STDIN_FILENO);
	dup2(fd->fd[1], STDOUT_FILENO);
	close(fd->fd[0]);
	close(fd->fd[1]);
	exec(cmd, env, pipes, fd);
	exit(1);
}

int	*fork_children(int **pipes, char **av, char **env, t_fd *fd)
{
	int	index;
	int	nbr_cmd;
	int	*pid;

	nbr_cmd = ft_tablen(av) - 3;
	if (!ft_strcmp(av[1], "here_doc"))
		nbr_cmd = ft_tablen(av) - 4;
	pid = ft_calloc(nbr_cmd + 1, sizeof(int));
	index = 0;
	while (index < nbr_cmd)
	{
		pid[index] = fork();
		if (!pid[index])
		{
			free(pid);
			read_child(pipes, av, index, fd);
			write_child(pipes, av, index, fd);
			if (!ft_strcmp(av[1], "here_doc"))
				execute_child(fd, av[index + 3], env, pipes);
			else
				execute_child(fd, av[index + 2], env, pipes);
		}
		index++;
	}
	return (free(fd->fd), pid);
}

int	main(int ac, char **av, char **env)
{
	int		**pipes;
	int		*pid;
	int		nbr_cmd;
	t_fd	*fd;

	if (ac < 5)
		return (ft_printf("./pipex infile cmd ... cmd outfile\n"), 1);
	fd = malloc(sizeof(t_fd));
	fd->fd_h = -1;
	nbr_cmd = ac - 3;
	if (!ft_strcmp(av[1], "here_doc"))
	{
		if (ac < 6)
			return (free(fd), ft_printf("invalid number of arguments\n"), 1);
		nbr_cmd = ac - 4;
		fd->fd_h = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		here_doc_put_in(av, fd->fd_h);
		close(fd->fd_h);
		fd->fd_h = open("here_doc", O_RDONLY);
		unlink("here_doc");
	}
	pipes = open_pipes(nbr_cmd - 1);
	fd->fd = ft_calloc(2, sizeof(int));
	pid = fork_children(pipes, av, env, fd);
	return (close_p(pipes, -1), free_p(pipes), free(fd), wait_children(pid));
}
