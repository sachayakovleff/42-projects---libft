/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:05:58 by syakovle          #+#    #+#             */
/*   Updated: 2023/04/16 14:47:14 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec1(t_pipex *pipex, char **envr)
{
	char	*cmd;
	char	**args;

	dup2(pipex->pipeid[1], 1);
	close(pipex->pipeid[0]);
	dup2(pipex->fd1, 0);
	cmd = ft_strjoin(pipex->path, pipex->cmd1);
	pipex->splitargs1 = ft_split(pipex->args1, ' ');
	execve(cmd, pipex->splitargs1, envr);
	perror("command not found\n");
	ft_freestr_array(pipex->splitargs1);
	ft_freechild(*pipex);
	free(cmd);
	exit(1);
}

void	ft_exec2(t_pipex *pipex, char **envr)
{
	char	*cmd;
	char	**args;

	dup2(pipex->pipeid[0], 0);
	close(pipex->pipeid[1]);
	dup2(pipex->fd2, 1);
	cmd = ft_strjoin(pipex->path, pipex->cmd2);
	pipex->splitargs2 = ft_split(pipex->args2, ' ');
	execve(cmd, pipex->splitargs2, envr);
	perror("command not found");
	ft_freechild(*pipex);
	ft_freestr_array(pipex->splitargs2);
	free(cmd);
	exit(1);
}
