#include <stdio.h>

int main(void) {
  //exercicio 5
  int linha, coluna, n_multiplicador, linha_selecionada;
  
  printf("\nDigite o numero de linha(s) da matriz:");
  scanf("%d", &linha);

  printf("\nDigite o numero de coluna(s) da matriz:");
  scanf("%d", &coluna);

  int matriz[linha][coluna];

  for(int i=0;i<linha;i++){ 
    for(int j=0; j<coluna; j++)
    {
      printf ("\n Digite o Elemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[i][j]);
    }
  }

  printf("\n\nDigite o numero que deseja multiplicar:");
  scanf("%d", &n_multiplicador);

  printf("\n\nDigite o numero da linha que sera multiplicada:");
  scanf("%d", &linha_selecionada);

  for (int i=0; i<=linha_selecionada; i++){
	  matriz[linha_selecionada-1][i] = n_multiplicador *  matriz[linha_selecionada-1][i];
  }

  printf("\n\n");
  for (int i=0; i<linha; i++ ){ 
    for (int j=0; j<coluna; j++ )
    {
      printf ("%d ", matriz[ i ][ j ]);
    }
    printf("\n");
  }

  
  return 0;
}
