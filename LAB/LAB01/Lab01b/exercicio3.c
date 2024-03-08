#include <stdio.h>

int main(void) {
  int n, i, j;
  printf("Digite o numero maximo (Deve ser ímpar!): ");
  scanf("%d", &n);
  if (n % 2 ==0){
    printf("Numero par/invalido.");
    return 1;
  } else {
    for( i = 0; i<= (n / 2) + 1; i++){
        for ( j = i + 1; j <= n - i; j++ ){
            printf("%d ",j);
          }
        printf("\n");
        for ( j = 0; j < (i + 1) * 2; j++ ){
            printf(" ");
        }
    }
    return 0;
  }
}
