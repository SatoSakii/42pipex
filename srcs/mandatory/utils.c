/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:34:51 by albernar          #+#    #+#             */
/*   Updated: 2024/11/05 23:24:21 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *s1, char *s2, int usage, int code)
{
	if (!usage && !s1 && s2)
	{
		ft_printf("File: %s\n", s2);
		perror("Error");
	}
	if (!usage && !s1 && !s2)
		perror("Error");
	if (s1)
	{
		ft_printf("Error: %s\n", s1);
		if (usage == 1)
			ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		else if (usage == 2)
			ft_printf("Exemple: ./pipex_bonus file1 cmd1 cmd2 cmd3.. file2\n");
	}
	exit(code);
}

void	free_strs(char **strs)
{
	char	**tmp;

	tmp = strs;
	while (*tmp)
		free(*tmp++);
	free(strs);
}
