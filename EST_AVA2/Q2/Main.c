// Libs

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include "funcoes.h"

// Funções Protótipos

int Selection(int type);
void switchPill(NodePill *PILHA);
void switchFila(NodeFila *FILA);
void switchArv(NodeArv *RAIZ);

// Int Main

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  bool loop = true;
  
  NodePill *PILHA = (NodePill *)malloc(sizeof(NodePill));
  PILHA->prox = NULL;
  PILHA->tam = 0;

  NodeFila *FILA = (NodeFila*) malloc(sizeof(NodeFila));
  FILA->prox = NULL;
  FILA->tam = 0;

  NodeArv *RAIZ = NULL;
  ArvB ARV;
  ARV.raiz = NULL;
  
  while(loop){
    switch(Selection(0)){
      case 1:
        switchPill(PILHA);
        break;
      case 2:
        switchFila(FILA);
        break;
      case 3:
        switchArv(RAIZ);
        break;
      default:
        loop = false;
        break;
    }
  }

  free(PILHA);
  free(FILA);

  printf("\n~~ Fim do Programa ~~");
  
  return 0;
}