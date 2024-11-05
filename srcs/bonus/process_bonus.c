/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:56:24 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 23:16:04 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(char *file, int flags, int mode)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd == -1)
		error_message(NULL, file, 0, 1);
	return (fd);
}

void	child_proc(char *cmd, char **envp)
{
	int	cpid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		error_message("Pipe failed: ", NULL, 0, 1);
	cpid = fork();
	if (cpid == -1)
		error_message("Fork failed: ", NULL, 0, 1);
	else if (cpid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		exec_command(cmd, envp, 0);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
	}
}
