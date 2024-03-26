#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



char *read_line();
int verificarComando(char **comandos);
char *verifica_espaco(char *linha);
int executa_processos(char **comandos);
void iniciarSistema();


int main()
{

    int controle = 1; 

    while (controle)
    {
        int i = 0, contador = 0;
        char *parte, *comando, **comandos = malloc(sizeof(char *) * 30);

        if (comandos == NULL)
        {
            printf("lsh: erro de alocacao\n");
            return 0;
        }

        iniciarSistema();
        parte = read_line();            // ler a parte digitada
        parte = verifica_espaco(parte); // tratar se a parte possui espaços em excesso

        comando = strtok(parte, ",");
        while (comando != NULL)
        {
            comandos[i] = comando;
            contador++;
            i++;
            comando = strtok(NULL, ",");
        }

        comandos[i] = NULL;
        i = 0;

        for (int z = 0; z < contador; z++)
        {
            char **copia = malloc(sizeof(char *) * 30);
            if (!copia)
            {
                fprintf(stderr, "lsh: erro de alocacao\n");
                return 0;
            }

            comando = strtok(comandos[z], " ");

            while (comando != NULL)
            { // pega todas as palavras da string
                copia[i] = comando;
                i++;
                comando = strtok(NULL, " ");
            }
            copia[i] = NULL;
            controle = verificarComando(copia);
            free(copia);
            if (controle == 0)
            {
                break;
            }
            i = 0;
        }

        
        free(comando);
        free(comandos);
        free(parte);
    }

    return 0;
}
char *read_line()
{
    int posicao = 0;
    char c, *buffer = malloc(sizeof(char) * 512);

    if (buffer == NULL)
    {
        printf("Erro de alocação\n");
        exit(1);
    }
    // ler caractere por caractere
    while (1)
    {

        c = getchar();

        // se chegar no EOF para e retorna a linha
        if (c == EOF || c == '\n')
        {
            buffer[posicao] = '\0';
            return buffer;
        }
        else
        {
            buffer[posicao] = c;
        }
        posicao++;
    }
}

int verificarComando(char **comandos)
{

    if (comandos[0] == NULL)
    {
        return 1;
    }
    if (strcmp(comandos[0], "exit") == 0)
    {
        return 0;
    }
    return executa_processos(comandos);
}

char *verifica_espaco(char *linha)
{
    int pos;
    for (int i = 0, pos = 0; i < strlen(linha); i++, pos++)
    {
        if (linha[pos] == ' ')
            if (linha[pos + 1] == ' ')
            {
                while (linha[pos + 1] == ' ')
                    pos++;
            }
        linha[i] = linha[pos];
    }

    return linha;
}

int executa_processos(char **comandos)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        
        if (execvp(comandos[0], comandos) == -1)
        {
            perror("lsh");
        }
        exit(1);
    }
    else if (pid < 0)
    {
        perror("lsh");
    }
    else
    {
        // Processo pai espera processo filho verificarComando
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1; // se deu tudo certo retorna 1
}
void iniciarSistema()
{

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