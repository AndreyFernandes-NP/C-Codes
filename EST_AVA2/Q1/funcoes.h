// Structs

// Funções

void imprimirVetor(float *v, int tam){
  int i;
  for (i = 0; i < tam; i++){
    if(i == 0){
      printf("\n\nVetor na ordem crescente: %.2f ", v[i]);
    }
    else{
      printf("| %.2f ", v[i]);
    }
  }
  printf("\n");
}

void BubbleSort(float *v, int tam){
  float maior;

  for(int i = 0; i < tam; i++){
    for(int j = i+1; j < tam; j++){
      if(v[i] > v[j]){
        maior = v[i];
        v[i] = v[j];
        v[j] = maior;
      }
    }
  }

  imprimirVetor(v, tam);
}

void InsertionSort(float *v, int tam){
  float chave;
  int i, j;
  
  for(i = 1; i < tam; i++) {
    chave = v[i];
    j = i - 1;
      
    while(j >= 0 && v[j] > chave) {
        v[j + 1] = v[j];
        j = j - 1;
    }
    v[j + 1] = chave;
  }

  imprimirVetor(v, tam);
}

int Selection(int type, int s){
  int escolha;

  if(type == 1){
    if(s != 1){
      printf("\n// Métodos de Ordenação \\\\\n");
      printf("Escolha qual a metodologia de ordenação você deseja utilizar no vetor recém criado.");
      printf("\n\n1 - Bubble Sort.\n2 - Insertion Sort.");
    }else{
      printf("\n\n1 - Bubble Sort.\n2 - Insertion Sort.");
    }
  
    printf("\nEscolha: ");
    scanf("%d", &escolha);

    return escolha;
  }else{
    printf("\n// Finalização \\\\\n");
    printf("Por fim, escolha uma das opções abaixo.\n\n");
    printf("1 - Criar outro vetor.\n2 - Encerrar o Programa.\nEscolha: ");
    scanf("%d", &escolha);

    switch(escolha){
      case 1:
        return 1;
      case 2:
        return 0;
      default:
        printf("Valor inválido, encerrando...");
        return 0;
    }
  }
}

bool Vetor(){
  int n, l=1, s=0;
  float *vetor;
  printf("\e[1;1H\e[2J");
  printf("// Definição do Vetor \\\\\n");
  
  printf("\nDigite o tamanho do vetor: ");
  scanf("%d", &n);
  vetor = (float *)malloc(n * sizeof(float));

  for(int i = 0; i < n; i++){
    printf("Digite o valor do %d° elemento do vetor: ", i+1);
    scanf("%f", &vetor[i]);
  }

  while(l==1){
    switch(Selection(1, s)){
      case 1:
        BubbleSort(vetor, n);
        l=0;
        break;
      case 2:
        InsertionSort(vetor, n);
        l=0;
        break;
      default:
        printf("\nValor inválido, repita.");
        s=1;
        break;
    }
  }

  return Selection(0, 0);
  
}