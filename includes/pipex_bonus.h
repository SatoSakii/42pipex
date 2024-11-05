/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:41:03 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 23:18:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

void	error_message(char *s1, char *s2, int usage, int code);
void	child_proc(char *cmd, char **envp);
void	here_doc(char *limiter, int argc);
void	exec_command(char *cmd, char **envp, int infile);
int		open_file(char *file, int flags, int mode);

#endif