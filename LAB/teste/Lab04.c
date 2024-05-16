#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
}; 
typedef struct reg celula;

int main() {
    // Alocando três instâncias da célula
    celula *primeira = (celula *)malloc(sizeof(celula));
    celula *segunda = (celula *)malloc(sizeof(celula));
    celula *terceira = (celula *)malloc(sizeof(celula));

    // Atribuindo valores
    primeira->conteudo = 1;
    primeira->prox = segunda;

    segunda->conteudo = 2;
    segunda->prox = terceira;

    terceira->conteudo = 3;
    terceira->prox = NULL;

    // Imprimindo os valores da lista
    void imprimeLista(celula *p) {
        while (p != NULL) {
            printf("%d ", p->conteudo);
            p = p->prox;
        }
        printf("\n");
    }

    imprimeLista(primeira);

    // Função para remover e liberar a memória da lista
    void removeLista(celula *p) {
        celula *tmp;
        while (p != NULL) {
            tmp = p;
            p = p->prox;
            free(tmp);
        }
    }

    // Removendo e liberando a memória
    removeLista(primeira);

    return 0;
}


