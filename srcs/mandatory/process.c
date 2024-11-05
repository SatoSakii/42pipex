/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:33:59 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 22:53:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(char **argv, char **envp, int pipefd[2])
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		error_message(NULL, argv[1], 0, 1);
	}
	dup2(pipefd[1], 1);
	dup2(infile, 0);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_command(argv[2], envp, infile);
	close(infile);
}

void	parent_proc(char **argv, char **envp, int pipefd[2])
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		error_message(NULL, NULL, 0, 1);
	}
	dup2(pipefd[0], 0);
	dup2(outfile, 1);
	close(pipefd[1]);
	close(pipefd[0]);
	exec_command(argv[3], envp, outfile);
	close(outfile);
}
