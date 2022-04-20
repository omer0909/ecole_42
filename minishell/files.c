/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:24:33 by ooz               #+#    #+#             */
/*   Updated: 2022/04/20 21:31:22 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_file_dir(char *command, int i, char name[], int n_len)
{
	int	j;
	int	in;

	while (command[i] == ' ' && n_len--)
		i++;
	in = in_quotes(command, i);
	if (in)
		command[i++] = ' ';
	j = 0;
	while (j < MAX_FILE_DIR - 1 && command[i] != '\0' && n_len--
		&& (command[i] != ' ' || in) && !in_quotes(command, i))
	{
		name[j++] = command[i];
		command[i++] = ' ';
	}
	if (in)
		command[i] = ' ';
	name[j] = '\0';
	cut_trim(name, "\"'");
}

int	get_file(char *command, int i, int flags)
{
	char	name[MAX_FILE_DIR];

	get_file_dir(command, i, name, MAX_FILE_DIR);
	return (open(name, flags, 0644));
}

int	get_out_files(int fd, char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '>' && !in_quotes(command, i))
		{
			if (fd != 1)
				close (fd);
			command[i] = ' ';
			if (command[i + 1] == '>')
			{
				command[++i] = ' ';
				fd = get_file(command, i, O_WRONLY | O_CREAT | O_APPEND);
			}
			else
				fd = get_file(command, i, O_WRONLY | O_CREAT | O_TRUNC);
		}
		i++;
	}
	return (fd);
}

int	ft_heredoc(char *command, int i)
{
	int		fd[2];
	char	*input;
	char	name[MAX_FILE_DIR];

	get_file_dir(command, i, name, MAX_FILE_DIR);
	pipe(fd);
	while (1)
	{
		input = readline("> ");
		if (!ft_strncmp(input, name, ft_strlen(name) + 1))
			break ;
		ft_putstr_fd(input, fd[1]);
		ft_putstr_fd("\n", fd[1]);
	}
	close(fd[1]);
	return (fd[0]);
}

int	get_in_files(int fd, char *command)
{
	int		i;
	int		old_fd;

	i = 0;
	while (command[i])
	{
		if (command[i] == '<' && !in_quotes(command, i))
		{
			old_fd = fd;
			command[i] = ' ';
			if (command[i + 1] == '<')
			{
				command[++i] = ' ';
				fd = ft_heredoc(command, i);
			}
			else
				fd = get_file(command, i, O_RDONLY);
			close(old_fd);
		}
		i++;
	}
	return (fd);
}
