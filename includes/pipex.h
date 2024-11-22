/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:21:47 by albernar          #+#    #+#             */
/*   Updated: 2024/11/16 08:36:52 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	int		*tab_pid;
	int		pid_count;
	int		exit_status;
	int		argc;
	char	**argv;
	char	**envp;
}			t_data;

void		error_message(char *message, char *file, int usage, int *tab);
void		free_strs(char **strs);
void		execute_last_cmd(char *cmd, t_data *data, int file[2],
				int pipefd[2]);
int			fork_pipe(t_data *data, int pipefd[2], int file[2], char *cmd);
void		child_process(t_data *data, int pipefd[2], int file[2], char *cmd);
char		*find_envpath(char *cmd, char **envp);
void		execve_command(char *cmd, t_data *data, int file[2]);
void		close_files(int fd_count, ...);
void		pipex(int start, t_data *data);

#endif