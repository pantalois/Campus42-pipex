/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:20:40 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/08 16:38:46 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

char **ft_getenv(char *env[], char *argv[]);
int	pipe_fork_creation(char *argv[], char *split_res[], int bolean, char *env[]);
int check_access(char *split_res[], char *argv[], char *env[], int j);
char **create_command(char *argv[]);

#endif
