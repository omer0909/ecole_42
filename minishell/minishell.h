/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:26:35 by ooz               #+#    #+#             */
/*   Updated: 2022/04/20 20:57:50 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"
# include <fcntl.h>

# define MAX_FILE_DIR 1024

typedef struct s_data
{
	char	**env;
	char	old_path[MAX_FILE_DIR];
	t_list	*pid_list;
	int		is_child;
	int		last_return;
	int		sig_int_sent;
	int		sig_quit_sent;
}	t_data;

typedef struct s_chdir
{
	char	my_path[MAX_FILE_DIR];
	char	old_path[MAX_FILE_DIR];
	char	**path;
}	t_chdir;

typedef struct s_process
{
	int	tmp_fd;
	int	fd[2];
	int	i;
}	t_process;

t_data	g_data;

char	**ft_split_quote(char const *s, char c);
void	ft_run(char **env, char **args);
char	*get_env_var(char *var);
void	error(char *str);
char	*ft_swap(char **a, char *b);
int		ft_command_compare(char *input, char *cmd);
int		in_quotes(const char *s, int i);
int		in_single_quotes(const char *s, int i);
void	cut_trim(char *str, char *set);
void	cut_all(char *str, char *set);
int		ft_builtin_commands(char *program, int fd_out);
void	export_env(char *command, int fd_out);
void	unset_env(char *command);
void	ft_print_env(int fd_out);
char	**ft_split_arg(char const *s, char c);
int		get_file(char *command, int i, int flags);
void	error(char *str);
int		in_quotes(const char *s, int i);
int		in_single_quotes(const char *s, int i);
void	active_signal(void);
void	ft_signals(void);
void	ft_setup_process(char **command);
void	ft_print_working_dir(int fd_out);
void	sig_quit_handler(int signum, siginfo_t *info, void *context);
char	*ft_set_var(char *cmd, int i);
int		get_in_files(int fd, char *command);
int		get_out_files(int fd, char *command);
void	ft_change_dir(char *input, int fd_out);
void	ft_free_split(char **str);

#endif
