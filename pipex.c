/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:07:09 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/22 19:09:56 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
	int i;
	char *env_path;

	i = 1;
    if (argc < 2)
		return (0);
	while (*argv[i])
	{
		if (ft_getenv(env, argv))
		{
			env_path = *ft_getenv(env, argv);
			break ;
		}
		else
			return (0);
	}
	return (0);
}

/*Mirar si el infile tiene permisos, 
 * si tiene permiso de escritura sigo, sino "ERROR"
 * despues comprueba que exista el comando 1, si no existe tengo que esperar a los demas hasta que acaben todos los procesos
 *creo la pipe
 *checkeo que exista el siguiente comando
 *creo outfile
