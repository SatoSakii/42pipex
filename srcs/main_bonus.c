/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:18:45 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 23:23:51 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	cmds_start;
	int	infile;
	int	outfile;

	cmds_start = 2;
	if (argc < 6)
		error_message("Too few arguments.", NULL, 2, 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		cmds_start++;
		outfile = open_file(argv[argc - 1], O_WRONLY
				| O_CREAT | O_APPEND, 0777);
		here_doc(argv[2], argc);
	}
	else
	{
		infile = open_file(argv[1], O_RDONLY, 0777);
		outfile = open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(infile, 0);
	}
	while (cmds_start < argc - 2)
		child_proc(argv[cmds_start++], envp);
	dup2(outfile, 1);
	exec_command(argv[argc - 2], envp, infile);
	return (0);
}
