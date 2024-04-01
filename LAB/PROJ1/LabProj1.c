#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Criação das contas bancarias e do limite de transcições (teste com numeros menores para verificar com clareza)
#define CONTAS 2
#define TRANSACOES 100

// Utilização de um struct para a criação das contas
struct ContaBancaria{
  int Dinheiro;
  pthread_mutex_t mutex;
};

struct ContaBancaria contas[CONTAS];

// Função de transferencia de dinheiro
void *transferencia(void *arg){
  int valor = rand() % 1000;
  int ContaFrom = rand() % CONTAS; // Conta que irá transferir dinheiro
  int ContaTo = rand() % CONTAS; // Conta que receberá dinheiro
  if (ContaFrom == ContaTo){
    printf("X Transação negada\n"); //Mensagem caso as contas sejam iguais
    return 0;
  }
  if (contas[ContaFrom].Dinheiro < valor){
    printf("X Conta sem dinheiro\n"); // Mensagem caso uma das contas não tenha dinheiro suficiente
    return 0;
  };
  
  pthread_mutex_lock(&contas[ContaFrom].mutex); // Trava a ContaFrom para não sofrer muitos acessos
  pthread_mutex_lock(&contas[ContaTo].mutex); // Trava a ContaTo para não sofrer muitos acessos

  // Simulação da transferência
  contas[ContaFrom].Dinheiro -= valor;
  contas[ContaTo].Dinheiro += valor;

  pthread_mutex_unlock(&contas[ContaTo].mutex); // Destrava a ContaTo
  pthread_mutex_unlock(&contas[ContaFrom].mutex); // Destrava a ContaFrom

  printf("- (Conta%d) transferiu [%d] para (Conta%d)\n", ContaFrom+1, valor, ContaTo+1);

  return 0;
};

//Main responsavel por realizar o código
int main(){
  pthread_t threads[TRANSACOES];
  srand(time(NULL));

  for (int i = 0; i < CONTAS; i++) {
    contas[i].Dinheiro = 1000; // Cada conta começará com 1000 
    pthread_mutex_init(&contas[i].mutex, NULL);
  }

  for (int i = 0; i < TRANSACOES; i++) {
    pthread_create(&threads[i], NULL, transferencia, NULL);
  }

  for (int i = 0; i < TRANSACOES; i++) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < CONTAS; i++) {
    pthread_mutex_destroy(&contas[i].mutex);
    printf("\n* Saldo na conta%d: [%d]", i+1, contas[i].Dinheiro);
  }
  return 0;
};
