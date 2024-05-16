#include <stdio.h>
#include <stdlib.h>

struct pessoa {
  int chegada;
  int direcao;
};

void escada(int n) {
  struct pessoa array[n]; // array de pessoas
  for (int i = 0; i < n; i++) { // para cada pessoa, definir o tempo de chegada e a direção
    scanf("%d %d", &array[i].chegada, &array[i].direcao);
  }

  int fim = array[0].chegada + 10; // primeira pessoa já entra na escada diretamente, tempo que acaba é o momento que chega + 10
  int esperando, direcaoescada = array[0].direcao; // direcaoescada vai ter a direção atual
  for (int i = 1; i < n; i++) { // passa por todas as outras pessoas
    if (array[i].chegada <= fim) { // se a pessoa chegar antes do último que entrou terminar de usar a escada
      if (array[i].direcao == direcaoescada) {  // vê se a direção é a mesma
        fim = array[i].chegada + 10; // atualiza o tempo
      } else { // se for diferente, não pode entrar
        esperando = 1;
      }
    } else { // se for maior, veja se tem alguém esperando
      if (esperando) { // se tiver, aumenta 10 do tempo, pois a pessoa entrou assim que deu (momento em que o último saiu)
        fim += 10;
        direcaoescada = direcaoescada == 1 ? 0 : 1; // muda a direção da escada
        i--; // decrementa o i para passar pela pessoa novamente
      } else { // se não tem ninguém esperando, é só entrar
        fim = array[i].chegada + 10; // muda o tempo para o momento em que chegou + 10
        direcaoescada = array[i].direcao; // muda a direção da escada
      }
      esperando = 0; // se tinha alguém esperando anteriormente, o mesmo já entrou
    }
  }
  if (esperando) { // depois de passar por todos, ainda é possível ter alguém esperando, se tiver, aumenta 10 do tempo
    fim += 10;
  }
  printf("Resultado = %d", fim);
}

int main() {
  int n;
  scanf("%d", &n);
  escada(n);
  return 0;
}
