// Libs

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoes.h"
#include "pilhas.h"
#include "filas.h"
#include "arvores.h"

// Funções Protótipos

// Int Main

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  
  NodePill *PILHA = (NodePill *)malloc(sizeof(NodePill));
  PILHA->prox = NULL;
  PILHA->tam = 0;

  NodeFila *FILA = (NodeFila*) malloc(sizeof(NodeFila));
  FILA->prox = NULL;
  FILA->tam = 0;

  NodeArv *raiz = NULL;
  ArvB arv;
  arv.raiz = NULL;

  

  free(PILHA);
  free(FILA);
  
  return 0;
}