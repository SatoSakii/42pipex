/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:36:39 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 22:42:36 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_envpath(char *cmd, char **envp)
{
	char	**paths;
	char	**tmp_paths;
	char	*path;

	while (!ft_strnstr(*envp, "PATH", 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	tmp_paths = paths;
	while (*tmp_paths)
	{
		path = ft_strjoin(*tmp_paths, "/", 0, 0);
		path = ft_strjoin(path, cmd, 1, 0);
		if (!access(path, F_OK))
		{
			free_strs(paths);
			return (path);
		}
		free(path);
		tmp_paths++;
	}
	free_strs(paths);
	return (NULL);
}

void	exec_command(char *cmd, char **envp, int file)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		error_message(NULL, NULL, 0, 1);
	cmd_path = find_envpath(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_strs(cmd_args);
		close(file);
		error_message(NULL, NULL, 0, 1);
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		free(cmd_path);
		free_strs(cmd_args);
		close(file);
		error_message(NULL, NULL, 0, 1);
	}
	free(cmd_path);
	free_strs(cmd_args);
}
