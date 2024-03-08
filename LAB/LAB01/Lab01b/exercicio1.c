#include <stdio.h>
int Matriz[3][3] = {45,13,69,420,28,777,22,708,1000};
int menor;
int main(void) {
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      printf(" [%d] ", Matriz[i][j]);
    }
    printf("\n");
  }
  menor = Matriz[0][0];
  for (int i = 0; i<3; i++){
    for (int j = 0; j<3; j++){
      if (Matriz[i][j] < menor){
          menor = Matriz[i][j];
      }
    }
  }
  printf("O menor é: %d", menor);
  printf("\n");
}
