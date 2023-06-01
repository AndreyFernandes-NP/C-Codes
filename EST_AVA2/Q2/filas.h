// Structs

typedef struct NodeFila{
  int conteudo, tam;
  struct NodeFila *prox;
}NodeFila;

// Funções

int VAZIA(NodeFila *FILA){
  if(FILA->prox == NULL){
    return 1;
  }else{return 0;}
}

void ENQUEUE(NodeFila *FILA){
  NodeFila *novo=(NodeFila*)malloc(sizeof(NodeFila));
  novo->prox = NULL;

  printf("Digite o novo item da fila: ");
  scanf("%d", &novo->conteudo);

  if(VAZIA(FILA)){
    FILA->prox=novo;
  }else{
    NodeFila *tmp = FILA->prox;
    while(tmp->prox != NULL){
      tmp = tmp->prox;
    }
    tmp->prox = novo;
  }
  FILA->tam++;
}

void DEQUEUE(NodeFila *FILA){
  if(FILA->prox == NULL){
    printf("Fila vazia.\n");
    Sleep(2000);
    return;
  }else{
    NodeFila *tmp = FILA->prox;
    FILA->prox = tmp->prox;
    FILA->tam--;
    printf("Removido: %d\n", tmp->conteudo);
    free(tmp);
    Sleep(2000);
  }
}

void IMPRIMEFILA(NodeFila *FILA){
  if(VAZIA(FILA)){
    printf("Fila vazia!\n");
    Sleep(2000);
    return;
  }
  NodeFila *tmp = FILA->prox;
  printf("Fila: %d", tmp->conteudo);
  tmp = tmp->prox;
  while(tmp != NULL){
    printf(" | %d", tmp->conteudo);
    tmp = tmp->prox;
  }
  printf("\nQuantidade de itens da fila: %d", FILA->tam);
  printf("\n");
  Sleep(3000);
}

void LIMPARFILA(NodeFila *FILA){
  bool loop = true;
  int ir=0;
  while(loop){
    if(FILA->prox == NULL){
      printf("Itens removidos da Fila: %d.\n", ir);
      Sleep(3000);
      return;
    }else{
      NodeFila *tmp = FILA->prox;
      FILA->prox = tmp->prox;
      FILA->tam--;
      ir++;
      free(tmp);
    }
  }
}

void FILAMAIOR(NodeFila *FILA){
  int maior=0;
  if(VAZIA(FILA)){
    printf("Fila vazia.\n");
    Sleep(2000);
    return;
  }else{
    NodeFila *tmp = FILA->prox;
    maior = tmp->conteudo;
    tmp = tmp->prox;
    while(tmp != NULL){
      if(tmp->conteudo > maior){
        maior = tmp->conteudo;
        tmp = tmp->prox;
      }else{
        tmp = tmp->prox;
      }
    }
    printf("Maior item da fila: %d\n", maior);
    Sleep(2000);
  }
}

void FILAMENOR(NodeFila *FILA){
  int menor;
  if(VAZIA(FILA)){
    printf("Fila vazia.\n");
    Sleep(2000);
    return;
  }else{
    NodeFila *tmp = FILA->prox;
    menor = tmp->conteudo;
    tmp = tmp->prox;
    while(tmp != NULL){
      if(tmp->conteudo < menor){
        menor = tmp->conteudo;
        tmp = tmp->prox;
      }else{
        tmp = tmp->prox;
      }
    }
    printf("Menor item da fila: %d\n", menor);
    Sleep(2000);
  }
}