// Structs

typedef struct NodeArv {
  int chave;
  struct NodeArv *esq;
  struct NodeArv *dir;
}NodeArv;

typedef struct {
  NodeArv *raiz;
  int tam;
} ArvB;

// Funções

int INSERIRARV(){
  int valor;
  printf("Valor a ser inserido: ");
  scanf("%d", &valor);
  return valor;
}

NodeArv* INSERCAO(NodeArv *RAIZ, int valor){
  if(RAIZ == NULL){
    NodeArv *novo = (NodeArv*)malloc(sizeof(NodeArv));
    novo->chave = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
  }else{
    if(valor < RAIZ->chave){
      RAIZ->esq = INSERCAO(RAIZ->esq, valor);
    }
    if(valor > RAIZ->chave){
      RAIZ->dir = INSERCAO(RAIZ->dir, valor);
    }
    return RAIZ;
  }
}

int REMOVERARV(){
  int item;
  printf("Valor a ser removido: ");
  scanf("%d", &item);
  return item;
}

NodeArv* REMOCAO(NodeArv *RAIZ, int item){
  if(RAIZ == NULL){
    printf("Valor não encontrado!\n");
    return NULL;
  }else{
    if(RAIZ->chave == item){
      if(RAIZ->esq == NULL && RAIZ->dir == NULL){
        free(RAIZ);
        return NULL;
      }else{
        if(RAIZ->esq == NULL || RAIZ->dir == NULL){
          NodeArv *aux;
          if(RAIZ->esq != NULL){
            aux = RAIZ->esq;
          }else{
            aux = RAIZ->esq;
          }
          free(RAIZ);
          return aux;
        }else{
          NodeArv *aux = RAIZ->esq;
          while(aux->dir != NULL){
            aux = aux->dir;
          }
          RAIZ->chave = aux->chave;
          aux->chave = item;
          RAIZ->esq = REMOCAO(RAIZ->esq, item);
        }
      }
    }else{
      if(item < RAIZ->chave){
        RAIZ->esq = REMOCAO(RAIZ->esq, item);
      }else{
        RAIZ->dir = REMOCAO(RAIZ->dir, item);
      }
      return RAIZ;
    }
  }
}

void INORDER(NodeArv *RAIZ){
  if(RAIZ != NULL){
    INORDER(RAIZ->esq);
    printf("Chave: %d\n", RAIZ->chave);
    INORDER(RAIZ->dir);
  }
}

int BUSCARARV(){
  int elemento;
  printf("Elemento a ser procurado: ");
  scanf("%d", &elemento);
  return elemento;
}

void PROCURA(NodeArv *RAIZ, int elemento){
  if(RAIZ == NULL){
    printf("Elemento não encontrado na árvore.\n");
    return;
  }else{
    if(RAIZ->chave == elemento){
      printf("Elemento encontrado na árvore!\n");
    }else{
      if(RAIZ->chave > elemento){
        PROCURA(RAIZ->esq, elemento);
      }else{
        PROCURA(RAIZ->dir, elemento);
      }
    }
  }
}

void OFFORDER(NodeArv *RAIZ){
  if(RAIZ != NULL){
    OFFORDER(RAIZ->dir);
    printf("Chave: %d\n", RAIZ->chave);
    OFFORDER(RAIZ->esq);
  }
}

void MAIORARV(NodeArv *RAIZ){
  if(RAIZ == NULL){
    printf("Nenhum elemento encontrado na árvore.\n");
    return;
  }else{
    if(RAIZ->dir == NULL){
      printf("Maior elemento da árvore: %d\n", RAIZ->chave);
    }else{
      MAIORARV(RAIZ->dir);
    }
  }
}