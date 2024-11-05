/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:29:36 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 22:34:34 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

int		ft_printf(const char *s, ...);
void	error_message(char *s1, char *s2, int usage, int code);
void	free_strs(char **strs);
char	*find_envpath(char *cmd, char **envp);
void	child_proc(char **argv, char **envp, int pipefd[2]);
void	parent_proc(char **argv, char **envp, int pipefd[2]);
void	exec_command(char *cmd, char **envp, int file);

#endif