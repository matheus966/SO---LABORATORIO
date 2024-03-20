#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int value = 5;
    int pipefd[2]; // Declara um array para o pipefd, onde pipefd[0] é a extremidade de leitura e pipefd[1] é a extremidade de escrita
    pid_t pid;

    if (pipe(pipefd) == -1) { // Verifica se houve erro na criação do pipe
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == 0) { /* processo filho */
        close(pipefd[0]); // Fecha a extremidade de leitura do pipe no processo filho
        printf("Entrei no filho!\n");
        value += 15;
        printf("CHILD: value = %d\n", value);
        // Escreve o valor atualizado no pipe
        write(pipefd[1], &value, sizeof(value));
        close(pipefd[1]); // Fecha a extremidade de escrita do pipe no processo filho
        return 0;
    }
    else if (pid > 0) { /* processo pai */
        int received_value;
        close(pipefd[1]); // Fecha a extremidade de escrita do pipe no processo pai
        wait(NULL);
        // Lê o valor atualizado do pipe
        read(pipefd[0], &received_value, sizeof(received_value));
        close(pipefd[0]); // Fecha a extremidade de leitura do pipe no processo pai
        printf("PARENT: value = %d\n", received_value);
        return 0;
    }
}
