/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:07:09 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/13 17:53:39 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
	int i;

	i = 0;
	//char *env_path;
	char **split_res;

    if (argc < 2)
		return (0);
	/*env_path = ft_getenv(env);*/
	//printf("%s\n", env_path);
	split_res = ft_getenv(env);
	printf("ooooooooooooooooooooo\n");
/*	
	while (split_res[i])
	{
		printf("ZZZ%sZZZ\n", split_res[i]);
		i++;
	}
*/
	//check_in_out(argv);//esto puedo hacerlo en la funcion de forks.
	check_commands(split_res, argv, env);
	return (0);
}

//Abir el infile, si no puedo abrirlo es que no tengo los permisos. si lo abro, cuando lo cierro?
// si tiene permiso de escritura sigo, sino "ERROR"
// despues comprueba que exista el comando 1, si no existe tengo que esperar a los demas hasta que acaben todos los procesos
 //creo la pipe
 //checkeo que exista el siguiente comando
// creo outfile

 //si no tengo permiso para el outfile no envio mensaje de error si es que estuviera mal el segundo comando
 //tendre que hacer un "funcion donde esten mis execve"
 //	
 //
 //
 //	Para comprobar como funciona el execve
 //
 //	char **arr;
 //arr = malloc(sizeof(char *) * 2);
 //arr[0] = "ls"
 //arr[1] = NULL;
 //execve("/bin/ls", arr, env)
 //printf("hola") si el execve ha sido lanzado desde el proceso padre no se podria leer el print
 
