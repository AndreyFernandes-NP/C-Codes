// Structs

typedef struct NodeArv {
  int chave, prof;
  struct NodeArv *esq;
  struct NodeArv *dir;
}NodeArv;

typedef struct {
  NodeArv *raiz;
  int tam;
} ArvB;

// Funções

NodeArv* inserir(NodeArv *raiz, int valor){
  if(raiz == NULL){
    NodeArv *novo = (NodeArv*)malloc(sizeof(NodeArv));
    novo->chave = valor;
    novo->prof++;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
  }else{
    if(valor < raiz->chave){
      raiz->esq = inserir(raiz->esq, valor);
    }
    if(valor > raiz->chave){
      raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
  }
}

NodeArv* remover(NodeArv *raiz, int item){
  if(raiz == NULL){
    printf("Valor não encontrado!\n");
    return NULL;
  }else{
    if(raiz->chave == item){
      if(raiz->esq == NULL && raiz->dir == NULL){
        free(raiz);
        return NULL;
      }else{
        if(raiz->esq == NULL || raiz->dir == NULL){
          NodeArv *aux;
          if(raiz->esq != NULL){
            aux = raiz->esq;
          }else{
            aux = raiz->esq;
          }
          free(raiz);
          return aux;
        }else{
          NodeArv *aux = raiz->esq;
          while(aux->dir != NULL){
            aux = aux->dir;
          }
          raiz->chave = aux->chave;
          aux->chave = item;
          raiz->esq = remover(raiz->esq, item);
        }
      }
    }else{
      if(item < raiz->chave){
        raiz->esq = remover(raiz->esq, item);
      }else{
        raiz->dir = remover(raiz->dir, item);
      }
      return raiz;
    }
  }
}

void imprimir(NodeArv *raiz){
  if(raiz != NULL){
    imprimir(raiz->esq);
    printf("Chave: %d / Profundidade: %d\n", raiz->chave, raiz->prof);
    imprimir(raiz->dir);
  }
}