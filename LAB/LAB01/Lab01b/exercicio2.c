#include <stdio.h>

int main(void) {
  float N1, N2, N3, ME, MA;
  printf("Primeira nota: ");
  scanf("%f", &N1);
  printf("Segunda nota: ");
  scanf("%f", &N2);
  printf("Terceira nota: ");
  scanf("%f", &N3);
  ME = (N1+N2+N3)/3;
  MA = (N1+N2*2+N3*3+ME)/7;
  printf("Média: %f\n", ME);
  printf("Média de Aproveitamento: %f\n", MA);
  if (ME >= 9) printf("Nota A");
  if (ME < 9 && ME >=7.5) printf("Nota B");
  if (ME < 7.5 && ME >= 6) printf("Nota C");
  if (ME < 6 && ME >= 4) printf("Nota D");
  if (ME < 4) printf("Nota E");
}
