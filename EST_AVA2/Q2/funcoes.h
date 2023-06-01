// Includes

#include "pilhas.h"
#include "filas.h"
#include "arvores.h"

// Funções Protótipos

void EMPILHA(NodePill *PILHA);
void DESEMPILHA(NodePill *PILHA);
void IMPRIMEPILHA(NodePill *PILHA);
void LIMPARPILHA(NodePill *PILHA);
void IMPRIMIRTOPO(NodePill *PILHA);

void ENQUEUE(NodeFila *FILA);
void DEQUEUE(NodeFila *FILA);
void IMPRIMEFILA(NodeFila *FILA);
void LIMPARFILA(NodeFila *FILA);
void FILAMAIOR(NodeFila *FILA);
void FILAMENOR(NodeFila *FILA);

int INSERIRARV();
int REMOVERARV();
int BUSCARARV();
NodeArv* INSERCAO(NodeArv *RAIZ, int valor);
NodeArv* REMOCAO(NodeArv *RAIZ, int item);
void INORDER(NodeArv *RAIZ);
void PROCURA(NodeArv *RAIZ, int elemento);
void OOFORDER(NodeArv *RAIZ);
void MAIORARV(NodeArv *RAIZ);

// Funções

int Selection(int type){
  int escolha;
  switch(type){
    case 0:
      system("cls");
      printf("// Menu de Estruturas \\\\\n");
      printf("Escolha qual estrutura deseja usar.");
      printf("\n\n1 - Executar Pilha.\n2 - Executar Fila.\n3 - Executar Árvore.\nSair - Qualquer outro número.\n\nEscolha: ");
      break;
    case 1:
      system("cls");
      printf("// Opções Pilha \\\\\n");
      printf("O que deseja fazer?");
      printf("\n\n1 - Empilhar.\n2 - Desempilhar.\n3 - Imprimir Pilha.\n4 - Limpar Pilha.\n5 - Imprimir Topo da Pilha.\nSair - Qualquer outro número.\n\nEscolha: ");
      break;
    case 2:
      system("cls");
      printf("// Opções Fila \\\\\n");
      printf("O que deseja fazer?");
      printf("\n\n1 - Enqueue.\n2 - Dequeue.\n3 - Imprimir Fila.\n4 - Limpar Fila.\n5 - Maior Elemento da Fila.\n6 - Menor Elemento da Fila.\nSair - Qualquer outro número.\n\nEscolha: ");
      break;
    case 3:
      system("cls");
      printf("// Opções Árvore \\\\\n");
      printf("O que deseja fazer?");
      printf("\n\n1 - Inserir na Árvore.\n2 - Remover da Árvore.\n3 - Imprimir em Ordem.\n4 - Buscar na Árvore.\n5 - Imprimir em Ordem Inversa.\n6 - Maior Elemento da Árvore.\nSair - Qualquer outro número.\n\nEscolha: ");
      break;
  }

  scanf("%d", &escolha);
  return escolha;
}

void switchPill(NodePill *PILHA){
  bool loop = true;
  while(loop){
    switch(Selection(1)){
      case 1:
        EMPILHA(PILHA);
        break;
      case 2:
        DESEMPILHA(PILHA);
        break;
      case 3:
        IMPRIMEPILHA(PILHA);
        break;
      case 4:
        LIMPARPILHA(PILHA);
        break;
      case 5:
        IMPRIMIRTOPO(PILHA);
        break;
      default:
        return;
    }
  }
}

void switchFila(NodeFila *FILA){
  bool loop = true;
  while(loop){
    switch(Selection(2)){
      case 1:
        ENQUEUE(FILA);
        break;
      case 2:
        DEQUEUE(FILA);
        break;
      case 3:
        IMPRIMEFILA(FILA);
        break;
      case 4:
        LIMPARFILA(FILA);
        break;
      case 5:
        FILAMAIOR(FILA);
        break;
      case 6:
        FILAMENOR(FILA);
        break;
      default:
        return;
    }
  }
}

void switchArv(NodeArv *RAIZ){
  bool loop = true;
  while(loop){
    switch(Selection(3)){
      case 1:
        RAIZ = INSERCAO(RAIZ, INSERIRARV());
        break;
      case 2:
        RAIZ = REMOCAO(RAIZ, REMOVERARV());
        break;
      case 3:
        printf("\n");
        INORDER(RAIZ);
        printf("\n");
        Sleep(5000);
        break;
      case 4:
        PROCURA(RAIZ, BUSCARARV());
        Sleep(3000);
        break;
      case 5:
        printf("\n");
        OFFORDER(RAIZ);
        printf("\n");
        Sleep(5000);
        break;
      case 6:
        MAIORARV(RAIZ);
        Sleep(3000);
        break;
      default:
        return;
    }
  }
}