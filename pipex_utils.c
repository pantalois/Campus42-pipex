/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:09:04 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/22 19:09:54 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

int check_write(char*argv[], char *split_res)
{
	if (argv[1]) 
		if (access(split_res, W_OK) == 0)
			return (0);
	return (0);
}
int check_access(char *split_res[], char *argv[])
{
	int i;

	i = 0;
	if (argv[1] && access(argv[1], W_OK) == -1)
		//escribir error
		//crear outfile vacio
		perror("no hay permisos W_OK para el infile");
	while (argv[2] && split_res[i])
	{
		split_res[i] = ft_strjoin(split_res[i],"/");
		printf("1. %s, punt: %p\n", split_res[i], split_res[i]);
		split_res[i] = ft_strjoin(split_res[i], argv[2]);
		printf("2. %s, punt: %p\n", split_res[i], split_res[i]);
		//printf("%s", split_res[i]);
		if (split_res[i] && access(split_res[i], F_OK) == 0)
		{
			printf("--------------\n");
			//llamar a la creacion de pipe 
			return (0);
		}
		if (!split_res[i])
		{
			/*if (access()) /bin/ls comprobar si tiene accesso al argv,
						si es asi return (0)*/
			perror("INFILE COMMAND No existe en el PATH");
			exit (127);
		}
		i++;
	}
	return (0);
}

char **ft_getenv(char *env[], char *argv[])
{
	int i;
	int j;
	char *env_path;
	char **split_res;

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		if((ft_strncmp(env[i], "PATH=", 5)) == 0) //puede que no te lo pase
		{
			env_path = env[i];
			//printf("%s", env_path);
		}
		i++;
	}
	split_res = ft_split(&env_path[5], ':');
	while (split_res[j])
	{
		if (!check_access(split_res, argv))
			return (0);
		j++;
	}
	return (split_res);
}
