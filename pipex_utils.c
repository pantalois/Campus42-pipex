/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:09:04 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/24 18:59:31 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pipe_fork_creation()//que reciba argv desde la posicion donde se quedo en la funcion anterior
{
	int pid;
	int	fd[2];

	if (pipe(fd) == -1)
		//mensaje de error
		return (0);
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		//while argv[i]
		//comprobar existencia
		//fork
		//ejecutar
	}
		return (0);
	}
	if (pid > 0)
	{
		//proceso padre)
		return (0);
	}
	return (0);
}
int check_access(char *split_res[], char *argv[])
{
	int i;
	int fd;

	i = 0;

	if (argv[1])
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			perror("no hay permisos de lectura");
			//escribir error
			//crear outfile vacio
			//si no tengo permiso obvio el siguiente comando y continua la ejecucion
	while (argv[2] && split_res[i])
	{
		split_res[i] = ft_strjoin(split_res[i],"/");
		split_res[i] = ft_strjoin(split_res[i], argv[2]);
		//printf("2. %s, punt: %p\n", split_res[i], split_res[i]);
		//printf("%s", split_res[i]);
		if (split_res[i] && access(split_res[i], F_OK | X_OK) == 0)
		{
			printf("--------------\n");
			//pipe_fork_creation(pasar argv desde la posicion en la que estoy)
			return (0);
		}
		if (!split_res[i])
		{
			if (access(argv[i], F_OK | X_OK) == 0);
			{
				pipe_fork_creation(&argv[i]);	
				return (0);
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
		if((ft_strncmp(env[i], "PATH=", 5)) == 0)
			env_path = env[i];
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
