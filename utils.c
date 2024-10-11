/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:21:48 by tbartocc          #+#    #+#             */
/*   Updated: 2024/10/11 11:56:49 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

/*
void	here_doc_put_in(char **av, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (!ft_strcmp(ret, av[2]))
		{
			free(ret);
			exit(127);
		}
		ft_putstr_fd(ret, p_fd[1]);
		ft_putchar_fd('\n', p_fd[1]);
		free(ret);
	}
}

void	here_doc(char **av)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
		here_doc_put_in(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY);
	else if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (ret == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		if (in_or_out == 0)
			ft_putstr_fd(": No such file or directory\n", 2);
		else
		{
			ft_putstr_fd(": ", 2);
			perror("");
		}
		return (-1);
	}
	return (ret);
}
*/

void	exec(char *cmd, char **env, int **pipes, t_fd *fd)
{
	char	**s_cmd;
	char	*path;

	if (!cmd)
		exit (0);
	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (!path)
	{
		ft_free_tab(s_cmd);
		free(fd->fd);
		free(fd);
		free_p(pipes);
		exit(0);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		free(fd->fd);
		free(fd);
		free_p(pipes);
		exit(127);
	}
}

int	wait_children(int *pid)
{
	int	i;
	int	status;
	int	exit_code;

	status = 0;
	exit_code = 0;
	i = 0;
	while (pid[i])
	{
		waitpid(pid[i], &status, 0);
		++i;
	}
	free(pid);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		exit_code = 128 + WTERMSIG(status);
	return (exit_code);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (!ft_strcmp(sub, name))
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(ft_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		return (ft_free_tab(allpath), NULL);
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		if (!access(exec, F_OK | X_OK))
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	free(allpath);
	ft_free_tab(s_cmd);
	return (cmd);
}

void	here_doc_put_in(char **av, int fd)
{
	char	*ret;

	ft_putstr_fd("> ", 1);
	ret = get_next_line(0);
	while (ret)
	{
		if (ft_strcmp(ret, av[2]) == 0)
		{
			free(ret);
			return ;
		}
		write(fd, ret, ft_strlen(ret));
		write(fd, "\n", 1);
		free(ret);
		ft_putstr_fd("> ", 1);
		ret = get_next_line(0);
	}
	ft_putstr_fd("bash: warning: here-document "
		"delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(av[2], 2);
	ft_putstr_fd("')\n", 2);
}
