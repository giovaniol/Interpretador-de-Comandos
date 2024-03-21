
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int verificaComando(char **comandos);
void iniciarSistema();
void receberComando();
int executaComando();

int main(int argc, char const *argv[])
{
    iniciarSistema();
    executaComando();
}
void receberComando()
{
}
int executaComando()
{
    char comando[] = "lambida do meu saco"; //Trocar para o argumento depois
    char *partes = strtok(comando, ","), **comandos = malloc(sizeof(char *) * 30);
    int i = 0;
    if (comandos == NULL)
    {
        printf("Falha na alocação de memória");
        return 1;
    }
    while (partes != NULL)
    {
        comandos[i] = partes;
        i++;
        partes = strtok(NULL, ",");
    }

    comandos[i] = NULL;
    int contador = i;
    i = 0;
}
int verificaComando(char **comandos)
{

    if (comandos[0] == NULL)
    {
        return 1;
    }
    if (strcmp(comandos[0], "exit") == 0)
    {
        return 1;
    }

    return executaComando(comandos);
}
void iniciarSistema(){
   
    char *nomeUsuario = getenv("USER");
    if (nomeUsuario != NULL)
    {
        printf("Olá, %s. Por favor, digite um comando: ", nomeUsuario);
    }
    else
    {
        printf("Falha na alocação.");
    }
}