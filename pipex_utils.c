/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:09:04 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/13 15:20:48 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
char **create_command(char *argv[])//esta funcion me aisla el comando que quiero pasarle al execve en caso de que nos pasen la ruta absoluta y no el comando
{
	char **command = NULL;
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
*/
int pipe_fork_creation(char *argv[], char *split_res[], int bolean, char *env[])//que reciba argv desde la posicion donde se quedo en la funcion anterior
{
	int pid;//ver por que la variable pid_t no me la detcta.
	int	fd[2];
	//char **path;
	int j;
	int z;

	j = 0;
	if (pipe(fd) == -1)
		{//mensaje de error
		return (0);
		}
		printf("fd[0] de la pipe = %i\n", fd[0]);
		printf("fd[1] de la pipe = %i\n", fd[1]);
		pid = fork();//Pasarla a una funcion a parte de creacion de hijos
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		check_in_out(argv);
		z = getpid();
		printf("pid == %d\n", z);
		printf("PROCESO HIJO\n");
		if (argv[j])
		{
		//comprobar existencia(EN VERDAD SI ESTAMOSAQUI YA HABRIAMOS COMPROBADO SU EXISTENCIA EN EL CHECK_ACCESS
		//ejecutar
			if (bolean)//ejecuamos con la ruta siendo split_res
			{
				if (argv[j + 1])//hacer split del comando
					argv[j + 1] = NULL;
				//ft_split_command
				printf("estamos ejecutando ls dentro del proceso hijo\n");
				//dup2 de los file descriptors e ir cerrando antes de ejecutar.
				if (execve(*split_res, argv, env) == -1)//proteger execve
				{
					printf("ENTRA EN EL CONTROL DE ERROR");
					if (j == 1)//si es el primer proceso
						exit (0);
					if (j > 1)//si no es el primer proceso
						exit (1);
				//del execve nos salimos con exit, sino nos queda un hijo zombie
				//cerrar el fd del comando anterior una vez ejecutado el proceso.
				}
				printf("pid == %d\n", z);
			}
			if (!bolean)
			{
				printf("ENTRA EN RUTA ABSOLUTA\n");
				//path = create_command(argv);
				//printf("path[0] = %s\n", path[0]);
				//printf("path[1] = %s\n", path[1]);
				if (argv[j + 1])
						argv[j + 1] = NULL;
				if (execve(*argv, argv, env) == -1)//mirar el man para setear bien el tema de los retornos en caso de error con errno
				{
					if (j == 1)
						exit (0);
					if (j > 1)
						exit (1);
				}
			}
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
int check_commands(char *split_res[], char *argv[], char *env[])
{
	
	int i;
	int j;
	int x;
	
	i = 0;
	j = 2;
	x = 2;
	while (split_res[i] && argv[j])
	{
		split_res[i] = ft_strjoin(split_res[i],"/");
		printf("%s\n", split_res[i]);
		split_res[i] = ft_strjoin(split_res[i], argv[j]);
		printf("%s\n", split_res[i]);
		//if (split_res[i] && access(split_res[i], F_OK | X_OK) == 0)// tendremos que comprobar que podamos ejecutar el comando en el execve
		{
			printf("--------------\n");
			if (argv[j])
			{
				pipe_fork_creation(&argv[j], &split_res[i], 1, env); //pasamos la ruta del env y tambien le pasamos un bool en positivo
				j++;
				i = -1;
				free(split_res);
				split_res = ft_getenv(env);
				//llamar a funcioin de split_res para splitear el enviroment que estara aparte.
			}
		}
		i++;
		x++;
	}
		if (!split_res[i])//en lugar de llegar al final decirle que si la primera posicion es una '/' que me lo tome como una ruta absoluta
		{
			if (access(argv[j], F_OK | X_OK) == 0)
			{
				pipe_fork_creation(&argv[j], split_res,  0, env);//pasamos un bool negativo para dferenciar si pasar la ruta absoluta o pasar solo la	
				j++;
				free(split_res);
				split_res = ft_getenv(env);
			}
			else
			{
			perror("INFILE COMMAND No existe en el PATH");
			exit (127);
			}
		}
	return (1);
}/*
return (0);
}*/

char	**ft_getenv(char *env[])
{
	//int i;
	int j;
	char *env_path;
	char **split_res;
	//char **split_res;

	//i = 0;
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
	printf("retornoretorno\n");
	split_res = ft_split(&env_path[5], ':');
	return (split_res);
}

	//hasta aqui la funcion de get enviroment
	//de aqui para abajo la funcion de split enviroment.
//char	**split_env(char *env_path, char *argv[], char *env[])
/*char **split_env(char *env_path)
{
	char **split_res;
//	int i;
//	int j;

	split_res = ft_split(&env_path[5], ':');
	j = 0;
	i = 0;
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
}*/

int check_in_out(char *argv[])
{
	int i;
	int fd;
	int x;
	int j;

	x = 0;
	i = 0;
	j = 1;
	fd = 0;
	while (argv[x + 1])//toda esta parte de crear el infile y el outfile sera otra funcion.
		x++;
	printf("EEE%sEEE\n", argv[j]);
	printf("%d\n", j);
	if (argv[j])
	{
		if ((fd = open(argv[j], O_RDONLY)) == -1)
		{			
			printf("no hay permisos de lectura\n");//perror
			fd = open(argv[x], O_CREAT | O_WRONLY | O_TRUNC, 0644);// flag de borrar y escribir y flag append para los bonuses
			exit (1);
		}
		else
		{
			fd = open(argv[x], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			j++;
		}
	}
	return (fd);
}
