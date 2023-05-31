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

void PUSH(NodePill *PILHA){
  NodePill *novo=(NodePill*)malloc(sizeof(NodePill));
  novo->prox = NULL;

  printf("Novo item: ");
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

void IMPRIME(NodePill *PILHA){
  if(vazia(PILHA)){
    printf("Pilha vazia!\n\n");
    return;
  }
  NodePill *tmp;
  tmp = PILHA->prox;
  printf("\nPilha: %d", tmp->item);
  tmp = tmp->prox;
  while(tmp != NULL){
    printf(" - %d", tmp->item);
    tmp = tmp->prox;
  }
  printf("\nQuantidade de itens da pilha: %d", PILHA->tam);
  printf("\n\n");
}

void POP(NodePill *PILHA){
  if(PILHA->prox == NULL){
    printf("Pilha já vazia.\n\n");
    return;
  }else{
    NodePill *ultimo = PILHA->prox;
    NodePill *penultimo = PILHA;

    while(ultimo->prox != NULL){
      penultimo = ultimo;
      ultimo = ultimo->prox;
    }
    printf("\nRemovido: %d\n", ultimo->item);
    free(ultimo);
    penultimo->prox = NULL;
    PILHA->tam--;
  }
}