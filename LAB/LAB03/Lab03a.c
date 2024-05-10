#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h> // For pipe

#define FIBER_STACK (1024 * 64)

int threadFunction(void* argument) {
    int* pipe_fd = (int*)argument;
    printf("Child thread executing\n");

    // Exemplo de troca de informações: enviar um valor para o processo pai através do pipe
    int data_to_send = 42;
    write(pipe_fd[1], &data_to_send, sizeof(int));

    return 0;
}

int main() {
    void* stack;
    pid_t pid;
    int pipe_fd[2]; // Descritores de arquivo para o pipe

    // Criar o pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    stack = malloc(FIBER_STACK);
    if (stack == NULL) {
        perror("malloc: could not allocate stack");
        exit(EXIT_FAILURE);
    }

    printf("Creating child thread\n");

    pid = clone(&threadFunction, (char*)stack + FIBER_STACK,
                SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, pipe_fd);

    if (pid == -1) {
        perror("clone");
        exit(EXIT_FAILURE);
    }

    // Fechar o descritor de escrita do pipe no processo pai
    close(pipe_fd[1]);

    int data_received;
    // Ler o valor enviado pela thread filho através do pipe
    read(pipe_fd[0], &data_received, sizeof(int));
    printf("Parent received data from child thread: %d\n", data_received);

    pid = waitpid(pid, 0, 0);
    if (pid == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    free(stack);
    printf("Child thread returned and stack freed.\n");

    return 0;
}

