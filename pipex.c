/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:07:09 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/24 18:54:27 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
	int i;

	i = 1;
    if (argc < 2)
		return (0);
	ft_getenv(env, argv);
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
 
