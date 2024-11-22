/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:21:47 by albernar          #+#    #+#             */
/*   Updated: 2024/11/16 06:47:14 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		cmds_start;

	if (argc != 5)
		error_message(NULL, NULL, 1, NULL);
	cmds_start = 2;
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.tab_pid = NULL;
	data.exit_status = 0;
	data.pid_count = 0;
	pipex(cmds_start, &data);
	return (WEXITSTATUS(data.exit_status));
}
