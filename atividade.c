

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 100000
#define TAM 131072

int main()
{
	pid_t pid;
	char comando[MAX], *argumentos[TAM], *ponteiro, *nomeUsuario = getenv("USER");
	int i;

	while (comando[0] != 1)
	{
		i = 0;

		printf("Olá, %s. Por favor, digite um comando: ", nomeUsuario);
		gets(comando);

		ponteiro = strtok(comando, " ");

		while (ponteiro)
		{
			argumentos[i] = ponteiro;
			ponteiro = strtok(NULL, " ");
			i++;
		}

		argumentos[i] = NULL;

		if (strcmp(argumentos[0], "cd") == 0)
		{
			if (strcmp(argumentos[1], "~") == 0)
			{
				char aux[100];
				strcpy(aux, "~");
				chdir(getenv("HOME"));
				printf("%s \n", getcwd(aux, 100));
			}
			else
			{
				char aux[100];
				strcpy(aux, argumentos[1]);
				chdir(aux);
				printf("\n%s", getcwd(aux, 100));
			}
		}
		else if (strcmp(argumentos[0], "exit") == 0)
		{
			return 0;
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				if (execvp(argumentos[0], argumentos) < 0)
				{
					printf("Erro\n");
				}
			}
			else
			{
				int flagFilho;
				waitpid(pid, &flagFilho, 0);
				if (flagFilho == -1)
				{
					printf("\nErro\n");
				}
			}
		}

		
	}

	

	
	return 0;
}
