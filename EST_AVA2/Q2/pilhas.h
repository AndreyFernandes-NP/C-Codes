// Structs

typedef struct NodePill {
  int item, tam;
  struct NodePill *prox;
}NodePill;

// Funções

int vazia(NodePill *PILHA){
  if(PILHA->prox == NULL){
    return 1;
  }else{return 0;}
}

void EMPILHA(NodePill *PILHA){
  NodePill *novo=(NodePill*)malloc(sizeof(NodePill));
  novo->prox = NULL;

  printf("Item a Empilhar: ");
  scanf("%d", &novo->item);

  if(vazia(PILHA)){
    PILHA->prox = novo;
  }else{
    NodePill *tmp = PILHA->prox;
    while(tmp->prox != NULL){
      tmp = tmp->prox;
    }
    tmp->prox = novo;
  }
  PILHA->tam++;
}

void IMPRIMEPILHA(NodePill *PILHA){
  if(vazia(PILHA)){
    printf("Pilha vazia!\n");
    Sleep(1000);
    return;
  }
  NodePill *tmp;
  tmp = PILHA->prox;
  printf("Pilha: %d", tmp->item);
  tmp = tmp->prox;
  while(tmp != NULL){
    printf(" | %d", tmp->item);
    tmp = tmp->prox;
  }
  printf("\nQuantidade de itens da pilha: %d", PILHA->tam);
  printf("\n");
  Sleep(3000);
}

void DESEMPILHA(NodePill *PILHA){
  if(PILHA->prox == NULL){
    printf("Pilha já vazia.\n");
    Sleep(1000);
    return;
  }else{
    NodePill *ultimo = PILHA->prox;
    NodePill *penultimo = PILHA;

    while(ultimo->prox != NULL){
      penultimo = ultimo;
      ultimo = ultimo->prox;
    }
    printf("Removido: %d\n", ultimo->item);
    free(ultimo);
    penultimo->prox = NULL;
    PILHA->tam--;
    Sleep(2000);
  }
}

void LIMPARPILHA(NodePill *PILHA){
  bool loop = true;
  int ir = 0;
  while(loop){
    if(PILHA->prox == NULL){
      printf("Pilha esvaziada, itens removidos: %d\n", ir);
      Sleep(2000);
      return;
    }else{
      NodePill *ultimo = PILHA->prox;
      NodePill *penultimo = PILHA;
      while(ultimo->prox != NULL){
      penultimo = ultimo;
      ultimo = ultimo->prox;
      }
      free(ultimo);
      penultimo->prox = NULL;
      PILHA->tam--;
      ir++;
    }
  }
}

void IMPRIMIRTOPO(NodePill *PILHA){
  if(vazia(PILHA)){
    printf("Pilha vazia!\n");
    Sleep(2000);
    return;
  }
  NodePill *tmp;
  tmp = PILHA->prox;
  while(tmp->prox != NULL){
    tmp = tmp->prox;
  }
  printf("Item no topo: %d", tmp->item);
  printf("\n");
  Sleep(2000);
}