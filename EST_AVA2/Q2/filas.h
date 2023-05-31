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
    return;
  }else{
    NodeFila *tmp = FILA->prox;
    FILA->prox = tmp->prox;
    FILA->tam--;
    free(tmp);
  }
}