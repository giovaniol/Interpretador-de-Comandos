
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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

    char frutas[] = "cd banana";
    executaComando(frutas);
    return 0;
}
void receberComando()
{
    // do
    // {
    // receberComando();
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
    char array[MAX];
    int tamanho = strlen(comando); // isto funciona só para delimitador de 1 caractere
    char *parte2 = strtok(comando, " ");
    char *parte1 = parte2;
    parte2 = strtok(NULL, " ");
    printf("Eu sou a parte 1 %s\n", parte1);
    printf("Eu sou a parte 2 %s\n", parte2);
    
    
}