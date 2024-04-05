#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define _INTEIRO_ 1
#define _INTEIRO_NEGATIVO_ 2
#define _P_FLUTUANTE_ 3
#define _P_FLUTUANTE_NEGATIVO_ 4
#define _ERRO_ 0

int scanner(char* palavra) {
    int estado = 0;
    char c;
    int i = 0;
    bool ponto = false;
    bool negativo = false;


    q0:
    c = palavra[i];
    if (c == '-') {
        negativo = true;
        i++;
        goto q1;
    } else if (c >= '0' && c <= '9') {
        i++;
        goto q2;
    } else {
        goto q7;
    }

    q1:
    c = palavra[i];
    if (c == '0') {
        goto q3;
    } else if (c >= '1' && c <= '9') {
        i++;
        goto q4;
    } else {
        goto q7;
    }

    q2:
    c = palavra[i];
    if (c >= '0' && c <= '9') {
        i++;
        goto q2;
    } else if (c == '.') {
        ponto = true;
        i++;
        goto q5;
    }else if (c == '-'){
        i++;
        goto q7;
    } else{
        return _INTEIRO_;
    }
        

    q3:
    c = palavra[i];
    if (c >= '1' && c <= '9') {
        i++;
        goto q4;
    }else if (c=='0'){
        i++;
        goto q3;
      }
    else if (c=='.'){
      ponto = true;
      i++;
      goto q9;
    
    } else {
        goto q7;
    }

    q4:
    c = palavra[i];
    if (c >= '0' && c <= '9') {
        i++;
        goto q4;
    }else if(c=='.'){
        i++;
        goto q10;
    }else if(c=='-'){
        i++;
        goto q7;
    }
    else {
        return _INTEIRO_NEGATIVO_;
      }
  q5:
    c = palavra[i];
    if(c >= '0' && c <= '9'){
      i++;
      goto q5;
    }
    else if (c == '.'|| c == '-'){
      goto q7;
    }
    else{
      return _P_FLUTUANTE_;
    }
  q6:
    c = palavra[i];
    if(c >= '0' && c <= '9'){
      i++;
      goto q6;
    }
  else if(c== '.'|| c == '-'){
    goto q7;
  }
  else{
    return _P_FLUTUANTE_NEGATIVO_;
  }
  
  q7:
    c = palavra[i];
    return _ERRO_;
  q8:
    c = palavra[i];
    if(c >= '0' && c <= '9'){ 
    i++;
    goto q8;
    }
    else if(c=='.' || c == '-'){
      goto q7;
    }
  else{
    return _P_FLUTUANTE_NEGATIVO_;
  }
  q9:
    c = palavra[i];
    if(c == '0'){
      i++;
      goto q9;
      
    }
    else if(c >= '0' && c <= '9') {
      i++;
      goto q8;
    }
    else{
      goto q7;
    }
   
q10:
    c = palavra[i]; 
    if(c== '.'|| c == '-'){
      goto q7;
    }
    else if(c >= '0' && c <= '9'){
      goto q6;
    }
    else{
      return _ERRO_;
      }
}
int main() {
    char palavra[100];
    printf("Digite a palavra: ");
    scanf("%s", palavra);

    int resultado = scanner(palavra);

    switch (resultado) {
        case _INTEIRO_:
            printf("<INTEIRO>\n");
            break;
        case _INTEIRO_NEGATIVO_:
            printf("<INTEIRO NEGATIVO>\n");
            break;
        case _P_FLUTUANTE_:
            printf("<P.FLUTUANTE>\n");
            break;
        case _P_FLUTUANTE_NEGATIVO_:
            printf("<P.FLUTUANTE NEGATIVO>\n");
            break;
        case _ERRO_:
            printf("<ERRO>\n");
            break;
    }

    return 0;
}
