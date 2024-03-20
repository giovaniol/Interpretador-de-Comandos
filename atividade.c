
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 50
// usar strcmp para comparar strings
// char comando[80];
// printf("\nPressione o comando: ");
// scanf("%s", comando);
// fflush(stdin);

char *args[] = {"ls", "-la", NULL};

void receberComando();
void executaComando(char comando[]);

int main(int argc, char const *argv[])
{
    char comando[MAX];

    char frutas[] = "ls -la bolacha biscoito";
    executaComando(frutas);
    return 0;
}
void receberComando()
{
    // do
    // {
    // receberComando()
    // } while (comando != "exit");
    // __pid_t boy;

    // printf("\nPressione o comando: ");
    // scanf("%s", comando);
    // boy = fork();
    // execve(comando, args);

    // fflush(stdin);
}
void executaComando(char comando[])
{
    
    char comando_copia[MAX];
    strcpy(comando_copia, comando);
    char **partes = NULL; 
    int contador = 0;

    char *parte = strtok(comando_copia, " ");

    // Aloca Todas as partes no Array Partes
    while (parte != NULL) {
        partes = realloc(partes, (contador + 1) * sizeof(char *)); // Aloca memória para um novo ponteiro
        partes[contador] = strdup(parte); // Aloca memória para uma cópia do parte e armazena no array
        contador++;
        parte = strtok(NULL, " ");
    }
    execve(partes[0], partes[1],  NULL);
    // Mostra todas as partes do comando
    for (int i = 0; i < contador; i++) {
        printf("Parte %d: %s\n", i + 1, partes[i]);
    }

    // Libera a memória alocada para cada parte e para o array de ponteiros
    for (int i = 0; i < contador; i++) {
        free(partes[i]);
    }
    free(partes);
    
}