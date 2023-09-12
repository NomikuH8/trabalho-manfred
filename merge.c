/*

PROCESSO AVALIATIVO N3 – ESTRUTURA DE DADOS

EQUIPE
NOMES:

CONSEGUIU CHEGAR NO RESULTADO?
R:

SE NÃO, POR QUE NÃO CONSEGUIU CHEGAR NO RESULTADO?
R.:

*/

#include <stdio.h>
#include <time.h>

#define TAMANHO 10000

void geraNumero(int *vet, int op);
void merge(int *arr, int p, int q, int r, int *comparacoes);
void mergeSort(int *arr, int l, int r, int *comparacoes);
void fazerMergeSort(int *vet);
void imprimirVetor(int *vet);

int main()
{
    int vet1[TAMANHO];

    geraNumero(vet1,3);
    fazerMergeSort(vet1);
    // imprimirVetor(vet1);

    return 0;
}

void geraNumero(int *vet, int op)
{
    int i, j;
    switch (op) {
        case 1: // Ordenados
            for (i = 0; i < TAMANHO; i++)
                vet[i] = i + 1;
            break;

        case 2: //Invertidos
            for (i = 0; i < TAMANHO; i++)
                vet[i] = TAMANHO - i;
            break;

        case 3: // Aleatórios
            for (i = 0; i < TAMANHO; i++)
                vet[i] = (int) (rand() % TAMANHO);
            break;
    }
}


void merge(int arr[], int p, int q, int r, int *comparacoes)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    *comparacoes += 1;
    k++;
  }

  while (i < n1) {
    *comparacoes += 1;
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    *comparacoes += 1;
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r, int *comparacoes)
{
  if (l < r) {
    *comparacoes += 1;

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, comparacoes);
    mergeSort(arr, m + 1, r, comparacoes);

    merge(arr, l, m, r);
  }
}


void fazerMergeSort(int *vet)
{
    int qtd_trocas, qtd_comparacoes;
    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();

    int size = sizeof(vet) / sizeof(vet[0]);

    mergeSort(vet, 0, size - 1, &qtd_comparacoes);

    float tempo_final = clock() - tempo_inicial;

    printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f",tempo_final/1000);
}

void imprimirVetor(int *vet)
{
    for(int i = 0; i < TAMANHO; i++)
    {
        printf("%i, ", vet[i]);
        if ((i + 1) % 14 == 0)
        {
            printf("\n");
        }
    }
}