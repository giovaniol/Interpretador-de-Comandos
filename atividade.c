#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MIN 20
#define MAX 30
int verificaComando(char **comandos);
void iniciarSistema();
int receberComando();
int executaComando();

int main(int argc, char const *argv[])
{
    iniciarSistema();
    executaComando();
    
    return 0;
}
int receberComando()
{
    char comando[]= "a lambida do meu saco";
    char *partes = strtok(comando, ","), **comandos = malloc(sizeof(char *) * 30);
    int i = 0, parar, controle = 0;
    if (comandos == NULL)
    {
        printf("Falha na alocação de memória");
        return 0;
    }
    while (partes != NULL)
    {
        comandos[i] = partes;
        i++;
        partes = strtok(NULL, ",");
    }
    comandos[i] = NULL;
    printf("%s\n", comandos[0]);

    int contador = i;
    i = 0;
    
    while (controle < contador)
    {
        char **copia = malloc(sizeof(char *) * 30);
        if (copia == NULL){
            printf("Falha na alocação de memória");

            return 0;
        }
        partes = strtok(comandos[controle], " ");
        while (partes != NULL){ 
            copia[i] = partes;
            i++;
            partes = strtok(NULL, " ");
        }
        copia[i] = NULL;
        parar = verificaComando(copia);
        free(copia);

        controle++;
    }
}
int executaComando()
{
    // Aparentemente, este código já executa como terminal, mesmo parecendo que o processo acaba.
    pid_t pid;
    int status, contador = 0;
    char *texto[MIN];
    
    pid = fork();
    if (pid != 0) {
        waitpid(pid, &status, 0);
        

    } else {
        char *comando, *param[MAX];
        comando = strtok(texto, ",");
        param[0] = comando;
        
        do {
            param[++contador] = strtok(NULL, ",");
        } while (param[contador] != NULL);

        execvp(comando, param);
        
        
        exit(EXIT_FAILURE);
    }
    
}

int verificaComando(char **comandos)
{
    

   
}
void iniciarSistema()
{

    char *nomeUsuario = getenv("USER");
    if (nomeUsuario != NULL)
    {
        printf("Olá, %s. Por favor, digite um comando: ", nomeUsuario);
        printf("\n");
    }
    else
    {
        printf("Falha na alocação.");
    }
}