/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:09:04 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/08 17:15:37 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **create_command(char *argv[])//esta funcion me aisla el comando que quiero pasarle al execve en caso de que nos pasen la ruta absoluta y no el comando
{
	char **command = '\0';
	int	i;
	int j;
	int z;

	i = ft_strlen(*argv);
	while (*argv[i - 1] != '/')
		i--;
	j = i;
	while (*argv[i])
		i++;
	i = i - j;
	command[0] = malloc(sizeof(char *) * i + 1);
	command[1] = malloc(sizeof(char *) * 1);
	z = 0;
	while (*argv[i])
	{
		command[0][z] = *argv[i];
		z++;
		i++;
	}
	command[0][z] = '\0';
	command[1] = NULL;
	printf("%s, %s", command[0], command[1]);
	return (command);
}

int pipe_fork_creation(char *argv[], char *split_res[], int bolean, char *env[])//que reciba argv desde la posicion donde se quedo en la funcion anterior
{
	int pid;//ver por que la variable pid_t no me la detcta.
	int	fd[2];
	char **path;
	int j;

	j = 0;
	if (pipe(fd) == -1)
		{//mensaje de error
		return (0);
		}
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		printf("PROCESO HIJO\n");
		while (argv[j])
		{
		//comprobar existencia(EN VERDAD SI ESTAMOSAQUI YA HABRIAMOS COMPROBADO SU EXISTENCIA EN EL CHECK_ACCESS
		//ejecutar
			if (bolean)//ejecuamos con la ruta siendo split_res
			{
				if (argv[j + 1])
					argv[j + 1] = NULL;
				printf("estamos ejecutando ls dentro del proceso hijo\n");
				execve(*split_res, argv, env);
				return (0);
			}
			if (!bolean)
			{
				printf("entro aqui\n");
				path = create_command(argv);
				execve(*argv, path, env);//mirar el man para setear bien el tema de los retornos en caso de error con errno
			}
		j++;
		}
		
	}
	if (pid > 0)
	{
		//proceso padre)
		wait(NULL);
		printf("YO SOY TU PADRE\n");
		return (0);
	}
	return (0);
}
int check_access(char *split_res[], char *argv[], char *env[], int j)
{
	int i;
	int fd;

	i = 0;
	printf("EEE%sEEE\n", argv[j]);
	printf("%d\n", j);
	if (argv[j])
	{
		if ((fd = open(argv[j], O_RDONLY)) == -1)
			printf("no hay permisos de lectura\n");
		else
			j++;
			//perror("no hay permisos de lectura");
			//escribir error
			//crear outfile vacio
			//si no tengo permiso obvio el siguiente comando y continua la ejecucion
	}
	while (split_res[i])
	{
		split_res[i] = ft_strjoin(split_res[i],"/");
		printf("%s\n", split_res[i]);
		split_res[i] = ft_strjoin(split_res[i], argv[j]);
		printf("%s\n", split_res[i]);
		if (split_res[i] && access(split_res[i], F_OK | X_OK) == 0)
		{
			printf("--------------\n");
			while (argv[j])
			{
				pipe_fork_creation(&argv[j], &split_res[i], 1, env); //pasamos la ruta del env y tambien le pasamos un bool en positivo
				j++;
			}
			return (0);
		}
		i++;
	}
		if (!split_res[i])
		{
			if (access(argv[j], F_OK | X_OK) == 0)
			{
				pipe_fork_creation(&argv[j], split_res,  0, env);//pasamos un bool negativo para dferenciar si pasar la ruta absoluta o pasar solo la	
				return (0);//no se por que tengo este return (0) aqui.
			}
			perror("INFILE COMMAND No existe en el PATH");
			exit (127);
		}
	return (1);
}/*
return (0);
}*/

char **ft_getenv(char *env[], char *argv[])
{
	int i;
	int j;
	char *env_path;
	char **split_res;

	i = 0;
	j = 0;
	while (env[j] != NULL)
	{
		if((ft_strncmp(env[j], "PATH=", 5)) == 0)
		{
			env_path = env[j];
			printf("%s\n", env_path);
		}
		j++;
	}
	split_res = ft_split(&env_path[5], ':');
	j = 0;
	while (split_res[i])
	{
		printf("AAA%sAAA\n", argv[j]);
		printf("%d\n", j);
		if (!check_access(split_res, &argv[j + 1], env, j))//aqui reutilizo la variable j una vez tengo el path controlado y paso directamente la posicion del argv que quiro para ese momento. 
			return (0);
		i++;
		j++;
	}
	return (split_res);
}
