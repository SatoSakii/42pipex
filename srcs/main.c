/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:18:45 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 22:36:50 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	cpid;

	if (argc < 5)
		error_message("Too few arguments.", NULL, 1, 1);
	if (argc > 5)
		error_message("Too many arguments.", NULL, 1, 1);
	if (pipe(pipefd) == -1)
		error_message("Pipe failed: ", NULL, 0, 1);
	cpid = fork();
	if (cpid == -1)
		error_message("Fork failed: ", NULL, 0, 1);
	else if (cpid == 0)
		child_proc(argv, envp, pipefd);
	else
		parent_proc(argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
