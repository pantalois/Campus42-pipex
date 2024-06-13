/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:20:40 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/13 14:43:08 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

char **ft_getenv(char *env[]);
int	pipe_fork_creation(char *argv[], char *split_res[], int bolean, char *env[]);
int check_commands(char *split_res[], char *argv[], char *env[]);
char **create_command(char *argv[]);
//char **split_env(char *env_path);
int check_in_out(char *argv[]);

#endif
