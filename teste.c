#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int verificaComando(char **parametros) {
    // Implement your command verification logic here
    // This function should return a value indicating whether the command is valid or not
    return 0; // Placeholder, change according to your logic
}

int main() {
    char texto_digitado[] = "ls -la"; // Example input, replace with user input
    int status;
    pid_t pid;

    pid = fork();
    if (pid != 0) {
        waitpid(pid, &status, 0);
    } else {
        char *comando;
        char *parametros[30];
        int contador = 0;

        comando = strtok(texto_digitado, ",");
        parametros[0] = comando;

        do {
            parametros[++contador] = strtok(NULL, ",");
        } while (parametros[contador] != NULL);

        execvp(comando, parametros);
        
        exit(EXIT_FAILURE);
    }

    // char *partes;
    // char comando[] = "ls -la"; // Example command, replace with actual input
    // char **comandos = malloc(sizeof(char *) * 30);
    // int i = 0, parar, controle = 0;

    // if (comandos == NULL) {
    //     printf("Falha na alocação de memória");
    //     return 0;
    // }

    // partes = strtok(comando, ",");
    // while (partes != NULL) {
    //     comandos[i] = partes;
    //     i++;
    //     partes = strtok(NULL, ",");
    // }
    // comandos[i] = NULL;

    // printf("%s\n", comandos[0]);

    // int contador = i;
    // i = 0;

    // while (controle < contador) {
    //     char **copia = malloc(sizeof(char *) * 30);
    //     if (copia == NULL) {
    //         printf("Falha na alocação de memória");
    //         return 0;
    //     }

    //     partes = strtok(comandos[controle], " ");
    //     while (partes != NULL) {
    //         copia[i] = partes;
    //         i++;
    //         partes = strtok(NULL, " ");
    //     }
    //     copia[i] = NULL;

    //     parar = verificaComando(copia);
    //     free(copia);

    //     controle++;
    // }
    // printf("%s\n", comandos[0]);

    // free(comandos);

    return 0;
}
