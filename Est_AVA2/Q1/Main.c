// Libs

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"

// Funções Protótipos

bool Vetor();

// Int Main

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  bool loop = true;
  
  while(loop){
    loop = Vetor();
  }

  printf("\n-- Fim do Programa --\n");
  
  return 0;
  
}