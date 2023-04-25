/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:05:58 by syakovle          #+#    #+#             */
/*   Updated: 2023/04/25 19:05:19 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char **envr)
{
	while (ft_strncmp("PATH", *envr, 4))
		envr++;
	return (*envr + 5);
}

void	ft_setenvr(t_pipex *pipex, char **envr)
{
	char	*temp;

	pipex->path = ft_find_path(envr);
	pipex->pathcmd = ft_split(pipex->path, ':');
	temp = ft_strdup(pipex->pathcmd[3]);
	pipex->path = ft_strjoin(temp, "/");
}

void	ft_exec1(t_pipex *pipex, char **envr)
{
	char	*cmd;

	ft_setenvr(pipex, envr);
	dup2(pipex->pipeid[1], 1);
	close(pipex->pipeid[0]);
	dup2(pipex->fd1, 0);
	cmd = ft_strjoin(pipex->path, pipex->cmd1);
	pipex->splitargs1 = ft_split(pipex->args1, ' ');
	execve(cmd, pipex->splitargs1, envr);
	ft_printf("Command '%s' not found\n", pipex->cmd1);
	ft_freestr_array(pipex->splitargs1);
	ft_freechild(*pipex);
	free(cmd);
	exit(1);
}

void	ft_exec2(t_pipex *pipex, char **envr)
{
	char	*cmd;

	ft_setenvr(pipex, envr);
	dup2(pipex->pipeid[0], 0);
	close(pipex->pipeid[1]);
	dup2(pipex->fd2, 1);
	cmd = ft_strjoin(pipex->path, pipex->cmd2);
	pipex->splitargs2 = ft_split(pipex->args2, ' ');
	execve(cmd, pipex->splitargs2, envr);
	ft_printf("Command '%s' not found\n", pipex->cmd2);
	ft_freechild(*pipex);
	ft_freestr_array(pipex->splitargs2);
	free(cmd);
	exit(1);
}
